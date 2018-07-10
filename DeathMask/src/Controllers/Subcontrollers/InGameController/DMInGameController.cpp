#include "DMInGameController.h"

#include <chrono>
#include <thread>
#include <iostream>
#include <FlameSteelCore/FSCMessage.h>
#include <DeathMask/src/Utils/DMUtils.h>
#include <DeathMask/src/Data/GameObjectsGenerator.h>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <FlameSteelFramework/FlameSteelCore/FSCUtils.h>
#include <DeathMask/src/Const/DMConstClassIdentifiers.h>
#include <FlameSteelEngineGameToolkitAlgorithms/Const/Const.h>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <FlameSteelEngineGameToolkitAlgorithms/Algorithms/MapGenerator/MapGenerator.h>
#include <FlameSteelEngineGameToolkitAlgorithms/Algorithms/MapGenerator/FSEGTAMapGeneratorParams.h>
#include <FlameSteelEngineGameToolkit/Controllers/FreeCameraController/FSEGTFreeCameraController.h>
#include <FlameSteelEngineGameToolkitAlgorithms/Algorithms/MazeObjectGenerator/FSGTAMazeObjectGenerator.h>
#include "GameplayRulesController.h"

using namespace DeathMaskGame;
using namespace FlameSteelEngine::GameToolkit::Algorithms;

DMInGameController::DMInGameController() {

};

void DMInGameController::generateMap() {

	objectsMap = make_shared<ObjectsMap>();

	auto mapGeneratorParams = make_shared<FSEGTAMapGeneratorParams>();

	shared_ptr<FSCObject> freeTile = std::make_shared<FSCObject>();
	shared_ptr<FSCObject> solidTile = std::make_shared<FSCObject>();
    
	mapGeneratorParams->freeTileIndex = 0;
	mapGeneratorParams->solidTileIndex = 1;

	mapGeneratorParams->tiles.push_back(freeTile);
	mapGeneratorParams->tiles.push_back(solidTile);
    
	mapGeneratorParams->maxIterations = 255;
	mapGeneratorParams->minCursorSize = 2;
	mapGeneratorParams->maxCursorSize = 1 + FSCUtils::FSCRandomInt(6);
	mapGeneratorParams->maxLineLength = 6 + FSCUtils::FSCRandomInt(6);
	mapGeneratorParams->gameplayObjectRespawnChance = 300;
	mapGeneratorParams->enemyRespawnChance = 300;

	auto objects = make_shared<FSCObjects>();
	auto objectsGenerator = make_shared<GameObjectsGenerator>();

	for (auto i = 0; i < 20; i++)
	{
		objects->addObject(objectsGenerator->generateRandomItem(Difficulty::easy));
	}

	mapGeneratorParams->objects = objects;

	enemies = make_shared<FSCObjects>();
	auto mapParametersEnemies = make_shared<FSCObjects>();

	for (auto i = 0; i < 20; i ++)
	{
		auto enemy = objectsGenerator->generateEnemy(Difficulty::easy);

		enemies->addObject(enemy);
		mapParametersEnemies->addObject(enemy);
	}

	mapGeneratorParams->enemies = mapParametersEnemies;

	auto gameMap = MapGenerator::generate(mapGeneratorParams, objectsContext);

	gameData->gameMap = gameMap;

	auto startPoint = objectsContext->objectWithInstanceIdentifier(make_shared<string>(ConstMapEntityStartPoint));

	if (startPoint.get() == nullptr)
	{
		throw logic_error("DMInGameController::beforeStart - no start point on map, can't place camera.");
	}

	auto text = make_shared<FSEGTText>(make_shared<string>("Start Point Entity"));
	text->setClassIdentifier(make_shared<string>(DMConstClassIdentifierLabel.c_str()));
	startPoint->addComponent(text);

	auto startPointPosition = FSEGTUtils::getObjectPosition(startPoint);

	if (startPointPosition.get() == nullptr)
	{
		throw logic_error("DMInGameController::beforeStart - no start point position, wrong object or incorrect arrangement.");
	}

	auto city = FSGTAMazeObjectGenerator::generate(gameMap);

	text = make_shared<FSEGTText>(make_shared<string>("City Model"));
	text->setClassIdentifier(make_shared<string>(DMConstClassIdentifierLabel.c_str()));
	city->addComponent(text);

	camera = FSEGTFactory::makeOnSceneObject(
      															make_shared<string>("camera"),
													           	make_shared<string>("camera"),
													           	shared_ptr<string>(),
															shared_ptr<string>(),
															shared_ptr<string>(),
													            startPointPosition->x, startPointPosition->y, startPointPosition->z,
													            1, 1, 1,
													            0, 0, 0,
													            0);   

	text = make_shared<FSEGTText>(make_shared<string>("Camera"));
	text->setClassIdentifier(make_shared<string>(DMConstClassIdentifierLabel.c_str()));
	camera->addComponent(text);

	text = make_shared<FSEGTText>(make_shared<string>("Main Character"));
	text->setClassIdentifier(make_shared<string>(DMConstClassIdentifierLabel.c_str()));
	mainCharacter->addComponent(text);

	playerObjectControls = make_shared<DMPlayerObjectControls>(mainCharacter, ioSystem->inputController, gameMap);

	auto mainCharacterPosition =  FSEGTUtils::getObjectPosition(mainCharacter);
	mainCharacterPosition->x = startPointPosition->x;
	mainCharacterPosition->y = startPointPosition->y;
	mainCharacterPosition->z = startPointPosition->z;

	auto gameplayProperties = make_shared<DMGameplayProperties>();
	mainCharacter->addComponent(gameplayProperties);

	gameplayProperties->setHealth(10);
	gameplayProperties->setHealthMax(10);
	gameplayProperties->setHunger(10);
	gameplayProperties->setHungerMax(10);
	gameplayProperties->setOxygen(10);
	gameplayProperties->setOxygenMax(10);
	gameplayProperties->creatureType = CreatureType::living;

	exitPoint =  objectsContext->objectWithInstanceIdentifier(make_shared<string>(ConstMapEntityEndPoint));

	if (exitPoint.get() == nullptr)
	{
		throw logic_error("DMInGameController::beforeStart - no exit point.");
	}

	text = make_shared<FSEGTText>(make_shared<string>("End Point Entity"));
	text->setClassIdentifier(make_shared<string>(DMConstClassIdentifierLabel.c_str()));
	exitPoint->addComponent(text);

	objectsContext->addObject(camera);    
	objectsContext->addObject(city);
	objectsContext->addObject(mainCharacter);

	//freeCameraController = make_shared<FSEGTFreeCameraController>(ioSystem->inputController, camera);
	//freeCameraController->delegate = shared_from_this();

	auto userInterfaceText = FSEGTFactory::makeOnScreenText(
						  make_shared<string>("User Interface"), 
						  0, 0.8);

	objectsContext->addObject(userInterfaceText);

	auto userInterfaceTextComponent = FSEGTUtils::getText(userInterfaceText);
	auto mainCharacterGameplayProperties = DMUtils::getObjectGameplayProperties(mainCharacter);

	auto versionText = FSEGTFactory::makeOnScreenText(
						  make_shared<string>("Death Mask"), 
						  0.7, 0.9);

	objectsContext->addObject(versionText);

	inGameUserInterfaceController = make_shared<DeathMaskGame::InGameUserInterfaceController>(userInterfaceTextComponent, mainCharacterGameplayProperties, shared_from_this());
	auto gameRulesObjects = make_shared<FSCObjects>();

	for (auto i = 0; i < enemies->size(); i++)
	{
		auto enemy = enemies->objectAtIndex(i);
		gameRulesObjects->addObject(enemy);
	}

	gameRulesObjects->addObject(mainCharacter);

	gameplayRulesController = make_shared<GameplayRulesController>(gameRulesObjects);
}

void DMInGameController::useItemAtXY(shared_ptr<FSCObjects> objects) {

	for (auto i = 0; i < objects->size(); i++) {
		auto object = objects->objectAtIndex(i);
		if (gameplayRulesController->objectTryingToUseItem(mainCharacter, object))
		{
			//TODO remove object at position
		}
	}
}

void DMInGameController::beforeStart() {
 
	mainCharacter = FSEGTFactory::makeOnSceneObject(
		make_shared<string>("main character"),
		make_shared<string>("main character"),
		shared_ptr<string>(),
 		shared_ptr<string>(),
		shared_ptr<string>(),
            0, 0, 0,
            1, 1, 1,
            0, 0, 0,
            0);   

	objectsContext->subscribe(shared_from_this());
	generateMap();   
 
}

shared_ptr<FSCObjects> DMInGameController::objectsForInGameUserInterfaceController(shared_ptr<InGameUserInterfaceController> inGameUserInterfaceController) {

	auto mainCharacterPosition = FSEGTUtils::getObjectPosition(mainCharacter);

	if (mainCharacterPosition.get() == nullptr)
	{
		throw logic_error("Cannot get objects for inGameUserInterface because main character position is null");
	}

	auto objects = objectsMap->objectsAtXY(mainCharacterPosition->x,mainCharacterPosition->z);

	return objects;

}

void DMInGameController::objectsContextObjectAdded(shared_ptr<FSEGTObjectsContext> context, shared_ptr<FSCObject> object) {

	objectsMap->handleObject(object);

}

void DMInGameController::objectsContextObjectUpdate(shared_ptr<FSEGTObjectsContext> context, shared_ptr<FSCObject> object) {

	objectsMap->handleObject(object);

}

void DMInGameController::objectsContextAllObjectsRemoved(shared_ptr<FSEGTObjectsContext> context) {

	objectsMap->removeAllObjects();

}

void DMInGameController::step() {

	handleMessages();
	frameStep();
	gameplayRulesController->step();

	for (auto i = 0; i < enemies->size(); i++)
	{
		auto enemy = enemies->objectAtIndex(i);
		auto enemyControls = DMUtils::getObjectControls(enemy);
		if (enemy.get() == nullptr)
		{
			throw logic_error("Can't control enemy - enemy controls are null");
		}
		enemyControls->step(shared_from_this());
	}

}

void DMInGameController::frameStep() {

auto inputController = ioSystem->inputController;

	playerObjectControls->step(shared_from_this());
	inGameUserInterfaceController->step();

	renderer->render(gameData);
	std::this_thread::sleep_for(0.01s);

      	inputController->pollKey();

	if (inputController->isExitKeyPressed()) {

		cout << "Bye-Bye!" << endl;
		ioSystem->stop();
		exit(0);

	}
	else if (inputController->isUseKeyPressed()) {

		auto mainCharacterPosition = FSEGTUtils::getObjectPosition(mainCharacter);

		if (mainCharacterPosition.get() == nullptr)
		{
			throw logic_error("Cannot use objects for because main character position is null");
		}

		auto objectsToUse = objectsMap->objectsAtXY(mainCharacterPosition->x,mainCharacterPosition->z);

		if (objectsToUse.get() == nullptr)
		{
			throw logic_error("Can't use empty objects");
		}

		useItemAtXY(objectsToUse);

	}
	else if (inputController->isShootKeyPressed()) {

		generateMap();
		return;

	}
	else {

		if (freeCameraController.get() != nullptr)
		{
			freeCameraController->step();
		}
		else
		{
			auto mainCharacterPosition =  FSEGTUtils::getObjectPosition(mainCharacter);
			auto cameraPosition = FSEGTUtils::getObjectPosition(camera);
			cameraPosition->x = mainCharacterPosition->x;
			cameraPosition->y = 0.5;
			cameraPosition->z = mainCharacterPosition->z;

			auto mainCharacterRotation = FSEGTUtils::getObjectRotation(mainCharacter);
			auto cameraRotation = FSEGTUtils::getObjectRotation(camera);
			cameraRotation->x = mainCharacterRotation->x;
			cameraRotation->y = mainCharacterRotation->y;
			cameraRotation->z = mainCharacterRotation->z;

			objectsContext->updateObject(camera);
		}
	}

	{
		auto mainCharacterPosition = FSEGTUtils::getObjectPosition(mainCharacter);
		auto exitPosition = FSEGTUtils::getObjectPosition(exitPoint);

		if (int(mainCharacterPosition->x) == int(exitPosition->x) && int(mainCharacterPosition->y) == int(exitPosition->y) && int(mainCharacterPosition->z) ==int(exitPosition->z)) {
		
			auto switchLevelMessage = make_shared<FSCMessage>(make_shared<string>("About gameplay process"), make_shared<string>("We need to switch level, because player step inside exit point."));
			messages.push_back(switchLevelMessage);

		}
	}

}

void DMInGameController::handleMessages() {

	if (messages.size() > 0)
	{
		generateMap();
		messages.pop_back();
	}
}

void DMInGameController::objectsControlsDelegateObjectDidUpdate(shared_ptr<FSCObject> object) {

	objectsContext->updateObject(object);
	objectsMap->handleObject(object);

}

void DMInGameController::freeCameraControllerDidUpdateCamera(shared_ptr<FSEGTFreeCameraController> freeCameraController, shared_ptr<FSCObject> camera) {

	objectsContext->updateObject(camera);
	objectsMap->handleObject(camera);

}