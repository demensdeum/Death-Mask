#include "DMInGameController.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <DeathMask/src/Algorithms/MapGenerator/DMMapGenerator.h>
#include <FlameSteelFramework/FlameSteelCore/FSCUtils.h>

DMInGameController::DMInGameController() {

};

void DMInGameController::beforeStart() {

	    auto cameraObject = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("camera"),
            make_shared<string>("camera"),
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

    gameData->gameMap = DMMapGenerator::generate(mapGeneratorParams, objectsContext);
    
    objectsContext->addObject(cameraObject);      
    //objectsContext->addObject(city);

}

void DMInGameController::step() {

	for(auto i = 0; i < 100; i++)
	{
		renderer->render(this->gameData);
		std::this_thread::sleep_for(0.01s);

        ioSystem->inputController->pollKey();

        if (ioSystem->inputController->isExitKeyPressed()) {

		cout << "Bye-Bye!" << endl;
		exit(0);

		}
      }
  
	cout << "Corrupted City Ended" << endl;

	exit(0);

};