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

#include <FlameSteelEngineGameToolkit/Data/FSEGTSimpleDirection.h>
#include <FlameSteelEngine/FSEUtils.h>
#include <iostream>

using namespace std;

DMMapGenerator::DMMapGenerator() {
}

DMMapGenerator::DMMapGenerator(const DMMapGenerator& orig) {
}

shared_ptr<FSEGTGameMap> DMMapGenerator::generate(shared_ptr<DMMapGeneratorParams> params) {

    auto gameMap = std::make_shared<FSEGTGameMap>();

    auto freeTileIndex = params->freeTileIndex;
    auto solidTileIndex = params->solidTileIndex;

    auto maxIterations = params->maxIterations;
    auto maxLineLength = params->maxLineLength;
    
    auto minCursorSize = params->minCursorSize;
    auto maxCursorSize = params->maxCursorSize;
    
    for (int x = 0; x < gameMap->width; x++) {
        
        for (int y = 0; y < gameMap->height; y++) {
            
            gameMap->setTileAtXY(solidTileIndex, x, y);
            
        }
    }
    
    int cursorX = FSEUtils::FSERandomInt(gameMap->width);
    int cursorY = FSEUtils::FSERandomInt(gameMap->height);
    
    if (cursorX < 2) { cursorX = 2; };
    if (cursorX > gameMap->width - 2) { cursorX = gameMap->width - 2; };

    if (cursorY < 2) { cursorY = 2; };
    if (cursorY > gameMap->height - 2) { cursorY = gameMap->height - 2; };    
    
    for (auto x = 0; x < maxIterations; x++) {

        int cursorDirection = FSEUtils::FSERandomInt(FSEGTSimpleDirectionCount);
        int cursorSteps = maxLineLength;        
        
        for (auto y = 0; y < cursorSteps; y++) {

            this->drawFreeTilesAtXY(gameMap, cursorX, cursorY, minCursorSize, maxCursorSize, freeTileIndex);

            switch (cursorDirection) {

                case FSEGTSimpleDirectionUp:

                    if (cursorY > 2) { cursorY -= 1; }

                    break;

                case FSEGTSimpleDirectionDown:

                    if (cursorY < gameMap->height - 2) { cursorY += 1; }

                    break;

                case FSEGTSimpleDirectionLeft:

                    if (cursorX > 2) { cursorX -= 1; }

                    break;

                case FSEGTSimpleDirectionRight:

                    if (cursorX < gameMap->width - 2) { cursorX += 1; }

                    break;
            }
        }
    }

    for (int x = 0; x < gameMap->width; x++) {
        
        for (int y = 0; y < gameMap->height; y++) {
            
            auto tileIndex = gameMap->getTileIndexAtXY(x, y);
            
            cout << tileIndex;
        }
        
        cout << endl;
    }    
    
    return gameMap;
}

void DMMapGenerator::drawFreeTilesAtXY(shared_ptr<FSEGTGameMap> gameMap, int cursorX, int cursorY, int minCursorSize, int maxCursorSize, int freeTileIndex) {
    
    int cursorSize = FSEUtils::FSERandomInt(maxCursorSize);
    
    if (cursorSize < minCursorSize) {
        
        cursorSize = minCursorSize;
        
    }
    
    for (int x = 0; x < cursorSize; x++) {
        
        for (int y = 0; y < cursorSize; y++) {
            
            int putTileX = x + cursorX;
            int putTileY = y + cursorY;
            
            if (putTileX < 2 || putTileY < 2 || putTileX > gameMap->width - 2 || putTileY > gameMap->height - 2) { continue; }
            
            gameMap->setTileAtXY(freeTileIndex, putTileX, putTileY);
            
        }
        
    }
    gameMap->setTileAtXY(freeTileIndex, cursorX, cursorY);    
    
}

DMMapGenerator::~DMMapGenerator() {
}

