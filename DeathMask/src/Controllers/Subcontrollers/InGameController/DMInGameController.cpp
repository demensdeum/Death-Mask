#include "DMInGameController.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <DeathMask/src/Algorithms/MapGenerator/DMMapGenerator.h>
#include <FlameSteelFramework/FlameSteelCore/FSCUtils.h>
#include <DeathMask/src/Algorithms/MazeObjectGenerator/DMMazeObjectGenerator.h>
#include <DeathMask/src/Data/GameMap/DMGameMap.h>
#include <FlameSteelEngineGameToolkit/Controllers/FreeCameraController/FSEGTFreeCameraController.h>

DMInGameController::DMInGameController() {

};

void DMInGameController::beforeStart() {

	    camera = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("camera"),
            make_shared<string>("camera"),
            make_shared<string>(),
            make_shared<string>(),
		make_shared<string>(),
            0, 0, 0,
            1, 1, 1,
            0, 0, 0,
            0);    
    
    auto mapGeneratorParams = make_shared<DMMapGeneratorParams>();

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

	auto gameMap = DMMapGenerator::generate(mapGeneratorParams, objectsContext);

    gameData->gameMap = gameMap;

    	      /*auto city = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("scene object"),
            make_shared<string>("revil"),
            shared_ptr<string>(),
            shared_ptr<string>(),
		make_shared<string>("Flame Steel Graphics Library Model @ Demens Deum\nModel version = Happy Sasquatch (1.0)\nMesh\nVertex - x = 0, y = -0.2, z = 0, u = 0, v = 1\nVertex - x = 1, y = -0.2, z = 0, u = 1, v = 1\nVertex - x = 1, y = -0.2, z = -1, u = 1, v = 0\nVertex - x = 0, y = -0.2, z = -1, u = 0, v = 0\nIndex = 0, 1, 2\nIndex = 3, 0, 2\nMaterial - Texture path = /home/demensdeum/Sources/Death-Mask/DeathMask/data/graphics/models/maps/corruptedCity/skytexture.bmp"),
		0,0,0,
            1, 1, 1,
		0,0,0,
            0);*/

		auto castedGameMap = static_pointer_cast<DMGameMap>(gameMap);
		auto city = DMMazeObjectGenerator::generate(castedGameMap);

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