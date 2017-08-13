/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMMapGenerator.cpp
 * Author: demensdeum
 * 
 * Created on April 25, 2017, 10:33 AM
 */

#include "DMMapGenerator.h"
#include "DeathMask/src/Data/GameMap/DMGameMap.h"

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTObjectsContext.h>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <FlameSteelEngineGameToolkit/Data/FSEGTSimpleDirection.h>
#include <FlameSteelCore/FSCUtils.h>
#include <iostream>

using namespace std;

DMMapGenerator::DMMapGenerator() {
}

DMMapGenerator::DMMapGenerator(const DMMapGenerator& orig) {
}

void DMMapGenerator::generate(shared_ptr<DMMapGeneratorParams> params, shared_ptr<FSEGTGameMap> gameMap, shared_ptr<FSEGTObjectsContext> objectsContext) {

    auto isMaskOnMap = false;

    auto castedGameMap = static_pointer_cast<DMGameMap>(gameMap);

    auto solidTileIndex = params->solidTileIndex;

    auto maxIterations = params->maxIterations;
    auto maxLineLength = params->maxLineLength;

    auto gameplayObjectRespawnChance = params->gameplayObjectRespawnChance;

    for (int x = 0; x < castedGameMap->width; x++) {

        for (int y = 0; y < castedGameMap->height; y++) {

            castedGameMap->setTileAtXY(solidTileIndex, x, y);
            castedGameMap->removeObjectIdAtXY(x, y);

        }
    }

    int cursorX = FSCUtils::FSCRandomInt(castedGameMap->width);
    int cursorY = FSCUtils::FSCRandomInt(castedGameMap->height);

    if (cursorX < 2) {
        cursorX = 2;
    };
    if (cursorX > castedGameMap->width - 2) {
        cursorX = castedGameMap->width - 2;
    };

    if (cursorY < 2) {
        cursorY = 2;
    };
    if (cursorY > castedGameMap->height - 2) {
        cursorY = castedGameMap->height - 2;
    };

    objectsContext->removeAllObjects();

    auto revil = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("scene object"),
            make_shared<string>("revil"),
            make_shared<string>(),
            make_shared<string>("./data/graphics/models/revil/revil"),
            cursorX, cursorY, 2,
            1, 1, 1,
            0, 0, 0,
            0);

    objectsContext->addObject(revil);

    this->drawFreeTilesAtXY(castedGameMap, params, cursorX, cursorY);

    for (auto x = 0; x < maxIterations; x++) {

        int cursorDirection = FSCUtils::FSCRandomInt(FSEGTSimpleDirectionCount);
        int cursorSteps = maxLineLength;

        for (auto y = 0; y < cursorSteps; y++) {

            rollDiceAndOnSuccessPutGameplayObjectIntoXY(cursorX, cursorY, gameplayObjectRespawnChance, objectsContext, castedGameMap);

            this->drawFreeTilesAtXY(castedGameMap, params, cursorX, cursorY);

            if (isMaskOnMap == false) {

                if (FSCUtils::FSCRandomInt(10) == 4) {

                    isMaskOnMap = true;

                    auto mask = FSEGTFactory::makeOnSceneObject(
                            make_shared<string>("scene object"),
                            make_shared<string>("mask"),
                            make_shared<string>(),
                            make_shared<string>("./data/graphics/models/mask/mask"),
                            cursorX, cursorY, 2,
                            1, 1, 1,
                            0, 0, 0,
                            0);

                    objectsContext->addObject(mask);

                    castedGameMap->setObjectIdAtXY(mask->id, cursorX, cursorY);
                    
                }

            }

            switch (cursorDirection) {

                case FSEGTSimpleDirectionUp:

                    if (cursorY > 2) {
                        cursorY -= 1;
                    }

                    break;

                case FSEGTSimpleDirectionDown:

                    if (cursorY < castedGameMap->height - 2) {
                        cursorY += 1;
                    }

                    break;

                case FSEGTSimpleDirectionLeft:

                    if (cursorX > 2) {
                        cursorX -= 1;
                    }

                    break;

                case FSEGTSimpleDirectionRight:

                    if (cursorX < castedGameMap->width - 2) {
                        cursorX += 1;
                    }

                    break;
            }
        }
    }

    // put exit

    auto exit = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("scene object"),
            make_shared<string>("exit"),
            make_shared<string>(),
            make_shared<string>("./data/graphics/models/exit/exit"),
            cursorX, cursorY, 2,
            1, 1, 1,
            0, 0, 0,
            0);

    objectsContext->addObject(exit);

    this->drawFreeTilesAtXY(castedGameMap, params, cursorX, cursorY);

    for (int y = 0; y < castedGameMap->width; y++) {

        for (int x = 0; x < castedGameMap->height; x++) {

            auto tileIndex = castedGameMap->getTileIndexAtXY(x, y);

            cout << tileIndex;
        }

        cout << endl;
    }
}

void DMMapGenerator::drawFreeTilesAtXY(shared_ptr<FSEGTGameMap> gameMap, shared_ptr<DMMapGeneratorParams> params, int cursorX, int cursorY) {

    auto minCursorSize = params->minCursorSize;
    auto maxCursorSize = params->maxCursorSize;

    auto freeTileIndex = params->freeTileIndex;

    int cursorSize = FSCUtils::FSCRandomInt(maxCursorSize);

    if (cursorSize < minCursorSize) {

        cursorSize = minCursorSize;

    }

    for (int x = 0; x < cursorSize; x++) {

        for (int y = 0; y < cursorSize; y++) {

            int putTileX = x + cursorX;
            int putTileY = y + cursorY;

            if (putTileX < 2 || putTileY < 2 || putTileX > gameMap->width - 2 || putTileY > gameMap->height - 2) {
                continue;
            }

            gameMap->setTileAtXY(freeTileIndex, putTileX, putTileY);

        }

    }

    gameMap->setTileAtXY(freeTileIndex, cursorX, cursorY);

}

void DMMapGenerator::rollDiceAndOnSuccessPutGameplayObjectIntoXY(int tileX, int tileY, int gameplayObjectRespawnChance, shared_ptr<FSEGTObjectsContext> objectsContext, shared_ptr<DMGameMap> gameMap) {

    if (FSCUtils::FSCRandomInt(gameplayObjectRespawnChance) == 0) {

        this->putGameplayObjectIntoXY(tileX, tileY, objectsContext, gameMap);

    }
}

void DMMapGenerator::putGameplayObjectIntoXY(int tileX, int tileY, shared_ptr<FSEGTObjectsContext> objectsContext, shared_ptr<DMGameMap> gameMap) {

    auto crate = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("scene object"),
            make_shared<string>("crate"),
            make_shared<string>(),
            make_shared<string>("./data/graphics/models/crate/crate"),
            tileX, tileY, 2,
            1, 1, 1,
            0, 0, 0,
            0);

    gameMap->setObjectIdAtXY(crate->id, tileX, tileY);

    objectsContext->addObject(crate);
}

DMMapGenerator::~DMMapGenerator() {
}

