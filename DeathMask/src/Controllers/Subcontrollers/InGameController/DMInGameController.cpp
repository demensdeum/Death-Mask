#include "DMInGameController.h"

#include <iostream>
#include <FlameSteelCore/Message.h>
#include <DeathMask/src/Utils/DMUtils.h>
#include <DeathMask/src/Data/GameObjectsGenerator.h>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <FlameSteelCore/FSCUtils.h>
#include <FlameSteelEngineGameToolkit/Const/FSEGTConst.h>
#include <DeathMask/src/Const/DMConstClassIdentifiers.h>
#include <FlameSteelEngineGameToolkitAlgorithms/Const/Const.h>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <DeathMask/src/Data/Components/Controls/ZombieControls/ZombieControls.h>
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

	shared_ptr<Object> freeTile = std::make_shared<Object>();
	shared_ptr<Object> solidTile = std::make_shared<Object>();
    
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

	auto objects = make_shared<Objects>();
	auto objectsGenerator = make_shared<GameObjectsGenerator>();

	for (auto i = 0; i < 20; i++)
	{
		objects->addObject(objectsGenerator->generateRandomItem(Difficulty::easy));
	}

	mapGeneratorParams->objects = objects;

	enemies = make_shared<Objects>();
	auto mapParametersEnemies = make_shared<Objects>();

	/*auto flag2D = FSEGTFactory::makeBooleanComponent();
	flag2D->setInstanceIdentifier(make_shared<string>(FSEGTConstComponentsFlag2D));
	flag2D->setClassIdentifier(make_shared<string>(FSEGTConstComponentsFlag2D));*/

	for (auto i = 0; i < 20; i ++)
	{
		auto enemy = objectsGenerator->generateEnemy(Difficulty::easy);
		//enemy->addComponent(flag2D);

		enemies->addObject(enemy);
		mapParametersEnemies->addObject(enemy);

		auto controls = DMUtils::getObjectZombieControls(enemy);
		controls->enableLookAt(mainCharacter);
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

	gameplayProperties->health = 100;
	gameplayProperties->healthMax = 100;
	gameplayProperties->synergy = 100;
	gameplayProperties->synergyMax = 100;

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

	auto mainCharacterGameplayProperties = DMUtils::getObjectGameplayProperties(mainCharacter);

	inGameUserInterfaceController = make_shared<DeathMaskGame::InGameUserInterfaceController>(camera,
																														mainCharacterGameplayProperties, 
																														 shared_from_this());
	auto gameRulesObjects = make_shared<Objects>();

	for (auto i = 0; i < enemies->size(); i++)
	{
		auto enemy = enemies->objectAtIndex(i);
		gameRulesObjects->addObject(enemy);
	}

	gameRulesObjects->addObject(mainCharacter);

	gameplayRulesController = make_shared<GameplayRulesController>(gameRulesObjects);

	uiObject = inGameUserInterfaceController->uiObject;

	objectsContext->addObject(inGameUserInterfaceController->uiObject);
}

void DMInGameController::useItemAtXY(shared_ptr<Objects> objects) {

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

shared_ptr<Objects> DMInGameController::objectsForInGameUserInterfaceController(shared_ptr<InGameUserInterfaceController> inGameUserInterfaceController) {

	auto mainCharacterPosition = FSEGTUtils::getObjectPosition(mainCharacter);

	if (mainCharacterPosition.get() == nullptr)
	{
		throw logic_error("Cannot get objects for inGameUserInterface because main character position is null");
	}

	auto objects = objectsMap->objectsAtXY(mainCharacterPosition->x,mainCharacterPosition->z);

	return objects;

}

void DMInGameController::objectsContextObjectAdded(shared_ptr<FSEGTObjectsContext> context, shared_ptr<Object> object) {

	objectsMap->handleObject(object);

}

void DMInGameController::objectsContextObjectUpdate(shared_ptr<FSEGTObjectsContext> context, shared_ptr<Object> object) {

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
	objectsContext->updateObject(uiObject);

	renderer->render(gameData);

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
			cameraPosition->y = mainCharacterPosition->y;
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
		
			auto switchLevelMessage = make_shared<Message>(make_shared<string>("About gameplay process"), make_shared<string>("We need to switch level, because player step inside exit point."));
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

void DMInGameController::objectsControlsDelegateObjectDidUpdate(shared_ptr<Object> object) {

	objectsContext->updateObject(object);
	objectsMap->handleObject(object);

}

void DMInGameController::freeCameraControllerDidUpdateCamera(shared_ptr<FSEGTFreeCameraController> freeCameraController, shared_ptr<Object> camera) {

	objectsContext->updateObject(camera);
	objectsMap->handleObject(camera);

}

bool DMInGameController::objectsControlsIsObjectCanMoveToPosition(shared_ptr<DMObjectControls> objectControls, shared_ptr<Object> object, shared_ptr<FSEGTVector> position) {

	auto gameMap = gameData->gameMap;
	if (gameMap.get() == nullptr) {
		throw logic_error("Game map is null");
	}

	auto tileX = int(position->x);
	auto tileY = int(position->z);

	auto tile = gameMap->getTileIndexAtXY(tileX, tileY);

	return tile == 0;
}