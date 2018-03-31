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
#include <DeathMask/src/Data/Components/GameplayProperties/DMGameplayProperties.h>
#include <DeathMask/src/Data/Components/TileProperties/DMTileProperties.h>
#include <DeathMask/src/Const/DMConstTypes.h>
#include <DeathMask/src/Utils/DMUtils.h>

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTObjectsContext.h>
#include <FlameSteelEngineGameToolkit/Data/FSEGTSimpleDirection.h>
#include "FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h"
#include <FlameSteelCore/FSCUtils.h>
#include <iostream>

using namespace std;

DMMapGenerator::DMMapGenerator() {
}

shared_ptr<FSEGTGameMap> DMMapGenerator::generate(shared_ptr<DMMapGeneratorParams> params, shared_ptr<FSEGTObjectsContext> objectsContext) {

	if (params.get() == nullptr) {

		cout << "DMMapGenerator: cannot generate map - params are nullptr" << endl;

		exit(1);
	}

	if (objectsContext.get() == nullptr) {

		cout << "DMMapGenerator: cannot generate map - objectsContext are nullptr" << endl;

		exit(1);
	}

	auto gameMap = make_shared<DMGameMap>();

    auto solidTileIndex = params->solidTileIndex;

    auto maxIterations = params->maxIterations;
    auto maxLineLength = params->maxLineLength;

    auto gameplayObjectRespawnChance = params->gameplayObjectRespawnChance;

    for (auto tile : params->tiles) {
        
        gameMap->addTile(tile);
        
    }
    
    for (int x = 0; x < gameMap->width; x++) {

        for (int y = 0; y < gameMap->height; y++) {

            for (auto layer = 0; layer < DMGameMapMaxLayers; layer++) {
                
                gameMap->setTileAtXY(solidTileIndex, x, y);
                gameMap->removeObjectIdAtXY(x, y, layer);
                
            }
        }
    }

    int cursorX = FSCUtils::FSCRandomInt(gameMap->width);
    int cursorY = FSCUtils::FSCRandomInt(gameMap->height);

    if (cursorX < 2) {
        cursorX = 2;
    }
    
    if (cursorX > gameMap->width - 2) {
        cursorX = gameMap->width - 2;
    }

    if (cursorY < 2) {
        cursorY = 2;
    }
    
    if (cursorY > gameMap->height - 2) {
        cursorY = gameMap->height - 2;
    }

    objectsContext->removeAllObjects();

    DMMapGenerator::drawFreeTilesAtXY(gameMap, params, cursorX, cursorY);

    for (auto x = 0; x < maxIterations; x++) {

        int cursorDirection = FSCUtils::FSCRandomInt(FSEGTSimpleDirectionCount);
        int cursorSteps = maxLineLength;

        for (auto y = 0; y < cursorSteps; y++) {

            DMMapGenerator::drawFreeTilesAtXY(gameMap, params, cursorX, cursorY);

            switch (cursorDirection) {

                case FSEGTSimpleDirectionUp:

                    if (cursorY > 2) {
                        cursorY -= 1;
                    }

                    break;

                case FSEGTSimpleDirectionDown:

                    if (cursorY < gameMap->height - 2) {
                        cursorY += 1;
                    }

                    break;

                case FSEGTSimpleDirectionLeft:

                    if (cursorX > 2) {
                        cursorX -= 1;
                    }

                    break;

                case FSEGTSimpleDirectionRight:

                    if (cursorX < gameMap->width - 2) {
                        cursorX += 1;
                    }

                    break;
            }
        }
    }

    DMMapGenerator::drawFreeTilesAtXY(gameMap, params, cursorX, cursorY);

    for (int y = 0; y < gameMap->width; y++) {

       for (int x = 0; x < gameMap->height; x++) {

            auto tileIndex = gameMap->getTileIndexAtXY(x, y);
		auto tile = gameMap->getTileAtXY(x, y);

		if (tile.get() == nullptr) {

			continue;

		}

		auto tileProperties = make_shared<DMTileProperties>();
		tile->addComponent(tileProperties);

		switch (tileIndex) {

			case 0:
				tileProperties->isFree = true;
				break;

			case 1:
				tileProperties->isFree = false;
				break;

			default:
				break;

		}

           cout << std::to_string(tileIndex);
        }

       cout << endl;
    }

	return gameMap;
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

DMMapGenerator::~DMMapGenerator() {
}