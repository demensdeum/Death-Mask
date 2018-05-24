#include "DMInGameController.h"

#include <chrono>
#include <thread>
#include <iostream>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <FlameSteelFramework/FlameSteelCore/FSCUtils.h>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <FlameSteelEngineGameToolkitAlgorithms/Algorithms/MapGenerator/MapGenerator.h>
#include <FlameSteelEngineGameToolkitAlgorithms/Algorithms/MapGenerator/FSEGTAMapGeneratorParams.h>
#include <FlameSteelEngineGameToolkit/Controllers/FreeCameraController/FSEGTFreeCameraController.h>
#include <FlameSteelEngineGameToolkitAlgorithms/Algorithms/MazeObjectGenerator/FSGTAMazeObjectGenerator.h>

using namespace FlameSteelEngine::GameToolkit::Algorithms;

DMInGameController::DMInGameController() {

};

void DMInGameController::beforeStart() {

	    	camera = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("camera"),
            make_shared<string>("camera"),
            shared_ptr<string>(),
            shared_ptr<string>(),
		shared_ptr<string>(),
            0, 0, 0,
            1, 1, 1,
            0, 0, 0,
            0);    
    
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

	auto city = FSGTAMazeObjectGenerator::generate(gameMap);

	objectsContext->addObject(camera);    
	objectsContext->addObject(city);

	freeCameraController = make_shared<FSEGTFreeCameraController>(ioSystem->inputController, camera);
	freeCameraController->delegate = shared_from_this();
}

void DMInGameController::step() {

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
}

void DMInGameController::freeCameraControllerDidUpdateCamera(shared_ptr<FSEGTFreeCameraController> freeCameraController, shared_ptr<FSCObject> camera) {

	objectsContext->updateObject(camera);

}