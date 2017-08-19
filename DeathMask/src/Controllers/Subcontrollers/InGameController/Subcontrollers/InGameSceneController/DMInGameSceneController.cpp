/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMInGameSceneController.cpp
 * Author: demensdeum
 * 
 * Created on August 19, 2017, 11:48 AM
 */

#include "DMInGameSceneController.h"

#include <DeathMask/src/Algorithms/MapGenerator/DMMapGenerator.h>
#include <DeathMask/src/Algorithms/MapGenerator/DMMapGeneratorParams.h>

#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <FlameSteelCore/FSCUtils.h>

#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>

#include <DeathMask/src/Data/GameMap/DMGameMap.h>

DMInGameSceneController::DMInGameSceneController() {
}

DMInGameSceneController::DMInGameSceneController(const DMInGameSceneController& orig) {
}

void DMInGameSceneController::generateMap() {

    objectsContext->removeAllObjects();

    auto mapGenerator = make_shared<DMMapGenerator>();

    auto mapGeneratorParams = make_shared<DMMapGeneratorParams>();

    mapGeneratorParams->freeTileIndex = 0;
    mapGeneratorParams->solidTileIndex = 1;

    mapGeneratorParams->maxIterations = 255;
    mapGeneratorParams->minCursorSize = 2;
    mapGeneratorParams->maxCursorSize = 1 + FSCUtils::FSCRandomInt(6);
    mapGeneratorParams->maxLineLength = 6 + FSCUtils::FSCRandomInt(6);

    mapGeneratorParams->gameplayObjectRespawnChance = 10;

    gameData->gameMap = make_shared<DMGameMap>();

    mapGenerator->generate(mapGeneratorParams, gameData->gameMap, this->objectsContext);

    for (auto x = 0; x < gameData->gameMap->width; x++) {

        for (auto y = 0; y < gameData->gameMap->height; y++) {

            auto tileIndex = gameData->gameMap->getTileIndexAtXY(x, y);

            if (tileIndex == 0) {

                auto floor = FSEGTFactory::makeOnSceneObject(
                        make_shared<string>("scene object"),
                        make_shared<string>("floor"),
                        make_shared<string>(),
                        make_shared<string>("./data/graphics/models/floor/floor"),
                        x, y, 1,
                        1, 1, 1,
                        0, 0, 0,
                        0);

                objectsContext->addObject(floor);

            } else if (tileIndex == 1) {

                auto wall = FSEGTFactory::makeOnSceneObject(
                        make_shared<string>("scene object"),
                        make_shared<string>("wall"),
                        make_shared<string>(),
                        make_shared<string>("./data/graphics/models/wall/wall"),
                        x, y, 2,
                        1, 1, 1,
                        0, 0, 0,
                        0);

                objectsContext->addObject(wall);
            }
        }
    }

    auto inventoryPrint = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("ui"),
            make_shared<string>("inventory print"),
            make_shared<string>(),
            make_shared<string>(),
            0.5, 0.5, 0.8,
            0.07, 1, 0.07,
            0, 0, 0,
            0);

    FSEGTUtils::setText(make_shared<string>("Death Mask - Prototype 1"), inventoryPrint);

    objectsContext->addObject(inventoryPrint);

    auto cameraObject = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("camera"),
            make_shared<string>("game camera"),
            make_shared<string>(),
            make_shared<string>(),
            0, 0, 0,
            1, 1, 1,
            0, 0, 0,
            0);

    objectsContext->addObject(cameraObject);
}

DMInGameSceneController::~DMInGameSceneController() {
}

