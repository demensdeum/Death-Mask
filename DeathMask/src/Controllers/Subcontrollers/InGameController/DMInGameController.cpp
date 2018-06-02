#include "DMInGameController.h"

#include <chrono>
#include <thread>
#include <iostream>
#include <FlameSteelCore/FSCMessage.h>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <FlameSteelFramework/FlameSteelCore/FSCUtils.h>
#include <FlameSteelEngineGameToolkitAlgorithms/Const/Const.h>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <FlameSteelEngineGameToolkitAlgorithms/Algorithms/MapGenerator/MapGenerator.h>
#include <FlameSteelEngineGameToolkitAlgorithms/Algorithms/MapGenerator/FSEGTAMapGeneratorParams.h>
#include <FlameSteelEngineGameToolkit/Controllers/FreeCameraController/FSEGTFreeCameraController.h>
#include <FlameSteelEngineGameToolkitAlgorithms/Algorithms/MazeObjectGenerator/FSGTAMazeObjectGenerator.h>

using namespace FlameSteelEngine::GameToolkit::Algorithms;

DMInGameController::DMInGameController() {

};

void DMInGameController::generateMap() {

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

    auto gameMap = MapGenerator::generate(mapGeneratorParams, objectsContext);

    gameData->gameMap = gameMap;

	auto startPoint = objectsContext->objectWithInstanceIdentifier(make_shared<string>(ConstMapEntityStartPoint));

	if (startPoint.get() == nullptr)
	{
		throw logic_error("DMInGameController::beforeStart - no start point on map, can't place camera.");
	}

	auto startPointPosition = FSEGTUtils::getObjectPosition(startPoint);

	if (startPointPosition.get() == nullptr)
	{
		throw logic_error("DMInGameController::beforeStart - no start point position, wrong object or incorrect arrangement.");
	}

	auto city = FSGTAMazeObjectGenerator::generate(gameMap);

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

	exitPoint =  objectsContext->objectWithInstanceIdentifier(make_shared<string>(ConstMapEntityEndPoint));

	if (exitPoint.get() == nullptr)
	{
		throw logic_error("DMInGameController::beforeStart - no exit point.");
	}

	objectsContext->addObject(camera);    
	objectsContext->addObject(city);

	freeCameraController = make_shared<FSEGTFreeCameraController>(ioSystem->inputController, camera);
	freeCameraController->delegate = shared_from_this();

}

void DMInGameController::beforeStart() {
 
	generateMap();   
 
}

void DMInGameController::step() {

	handleMessages();
	frameStep();
}

void DMInGameController::frameStep() {

auto inputController = ioSystem->inputController;

	renderer->render(gameData);
	std::this_thread::sleep_for(0.01s);

      	inputController->pollKey();

	if (inputController->isExitKeyPressed()) {

		cout << "Bye-Bye!" << endl;
		exit(0);

	}
	else {

		freeCameraController->step();

	}

	{
		auto cameraPosition = FSEGTUtils::getObjectPosition(camera);
		auto exitPosition = FSEGTUtils::getObjectPosition(exitPoint);

		if (int(cameraPosition->x) == int(exitPosition->x) && int(cameraPosition->y) == int(exitPosition->y) && int(cameraPosition->z) ==int(exitPosition->z)) {
		
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

void DMInGameController::freeCameraControllerDidUpdateCamera(shared_ptr<FSEGTFreeCameraController> freeCameraController, shared_ptr<FSCObject> camera) {

	objectsContext->updateObject(camera);

}