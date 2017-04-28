/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMInGameController.cpp
 * Author: demensdeum
 * 
 * Created on April 26, 2017, 8:42 AM
 */

#include "DMInGameController.h"

#include <FlameSteelEngine/FSEUtils.h>

#include <DeathMask/src/Algorithms/MapGenerator/DMMapGenerator.h>
#include <DeathMask/src/Algorithms/MapGenerator/DMMapGeneratorParams.h>

#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>

DMInGameController::DMInGameController() {
}

DMInGameController::DMInGameController(const DMInGameController& orig) {
}

void DMInGameController::beforeStart() {

    auto mapGenerator = std::make_shared<DMMapGenerator>();

    auto mapGeneratorParams = std::make_shared<DMMapGeneratorParams>();
    mapGeneratorParams->freeTileIndex = 0;
    mapGeneratorParams->solidTileIndex = 1;

    mapGeneratorParams->maxIterations = 255;
    mapGeneratorParams->maxCursorSize = 1 + FSEUtils::FSERandomInt(6);
    mapGeneratorParams->maxLineLength = 6 + FSEUtils::FSERandomInt(6);

    auto gameMap = mapGenerator->generate(mapGeneratorParams);

    gameData->gameMap = gameMap;
    
    for (auto x = 0; x < gameData->gameMap->width; x++) {

        for (auto y = 0; y < gameData->gameMap->height; y++) {

            auto tileIndex = gameData->gameMap->getTileIndexAtXY(x, y);

            if (tileIndex == 0) {
                
                auto floor = FSEGTFactory::makeOnSceneObject(
                        std::make_shared<string>("block"),
                        std::make_shared<string>("block"),
                        std::make_shared<string>(),
                        std::make_shared<string>("./data/graphics/models/floor/floor"),
                        x, y, 1,
                        1, 1, 1,
                        0, 0, 0,
                        0);

                this->gameData->getGameObjects()->addObject(floor);                
            }
            else if (tileIndex == 1) {

                auto wall = FSEGTFactory::makeOnSceneObject(
                        std::make_shared<string>("block"),
                        std::make_shared<string>("block"),
                        std::make_shared<string>(),
                        std::make_shared<string>("./data/graphics/models/wall/wall"),
                        x, y, 2,
                        1, 1, 1,
                        0, 0, 0,
                        0);

                this->gameData->getGameObjects()->addObject(wall);
            }
        }
    }
}

void DMInGameController::step() {

    renderer->render(gameData);

}

DMInGameController::~DMInGameController() {
}

