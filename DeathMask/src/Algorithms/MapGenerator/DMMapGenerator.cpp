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

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTObjectsContext.h>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <FlameSteelEngineGameToolkit/Data/FSEGTSimpleDirection.h>
#include <FlameSteelEngine/FSEUtils.h>
#include <iostream>

using namespace std;

DMMapGenerator::DMMapGenerator() {
}

DMMapGenerator::DMMapGenerator(const DMMapGenerator& orig) {
}

void DMMapGenerator::generate(shared_ptr<DMMapGeneratorParams> params, shared_ptr<FSEGTGameMap> gameMap, shared_ptr<FSEGTObjectsContext> objectsContext) {

    auto solidTileIndex = params->solidTileIndex;

    auto maxIterations = params->maxIterations;
    auto maxLineLength = params->maxLineLength;
    
    auto gameplayObjectRespawnChance = params->gameplayObjectRespawnChance;    
    
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
    
    objectsContext->removeAllObjects();
    
    auto revil = FSEGTFactory::makeOnSceneObject(
            std::make_shared<string>("revil"),
            std::make_shared<string>("revil"),
            std::make_shared<string>(),
            std::make_shared<string>("./data/graphics/models/revil/revil"),
            cursorX, cursorY, 2,
            1, 1, 1,
            0, 0, 0,
            0);

    objectsContext->addObject(revil);    
    
    this->drawFreeTilesAtXY(gameMap, params, cursorX, cursorY);    
    
    for (auto x = 0; x < maxIterations; x++) {

        int cursorDirection = FSEUtils::FSERandomInt(FSEGTSimpleDirectionCount);
        int cursorSteps = maxLineLength;        
        
        for (auto y = 0; y < cursorSteps; y++) {

            rollDiceAndOnSuccessPutGameplayObjectIntoXY(cursorX, cursorY, gameplayObjectRespawnChance, objectsContext);
            
            this->drawFreeTilesAtXY(gameMap, params, cursorX, cursorY);

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
    
    // put exit
    
    auto exit = FSEGTFactory::makeOnSceneObject(
            std::make_shared<string>("exit"),
            std::make_shared<string>("exit"),
            std::make_shared<string>(),
            std::make_shared<string>("./data/graphics/models/exit/exit"),
            cursorX, cursorY, 2,
            1, 1, 1,
            0, 0, 0,
            0);

    objectsContext->addObject(exit);  

    this->drawFreeTilesAtXY(gameMap, params, cursorX, cursorY); 
    
    for (int y = 0; y < gameMap->width; y++) {
        
        for (int x = 0; x < gameMap->height; x++) {
            
            auto tileIndex = gameMap->getTileIndexAtXY(x, y);
            
            cout << tileIndex;
        }
        
        cout << endl;
    }    
}

void DMMapGenerator::drawFreeTilesAtXY(shared_ptr<FSEGTGameMap> gameMap, shared_ptr<DMMapGeneratorParams> params, int cursorX, int cursorY) {
    
    auto minCursorSize = params->minCursorSize;
    auto maxCursorSize = params->maxCursorSize;
    
    auto freeTileIndex = params->freeTileIndex;
    
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

void DMMapGenerator::rollDiceAndOnSuccessPutGameplayObjectIntoXY(int tileX, int tileY, int gameplayObjectRespawnChance, shared_ptr<FSEGTObjectsContext> objectsContext) {
    
    if (FSEUtils::FSERandomInt(gameplayObjectRespawnChance) == 0) {
     
        this->putGameplayObjectIntoXY(tileX, tileY, objectsContext);
        
    }
}

void DMMapGenerator::putGameplayObjectIntoXY(int tileX, int tileY, shared_ptr<FSEGTObjectsContext> objectsContext) {
    
    auto exit = FSEGTFactory::makeOnSceneObject(
            std::make_shared<string>("crate"),
            std::make_shared<string>("crate"),
            std::make_shared<string>(),
            std::make_shared<string>("./data/graphics/models/crate/crate"),
            tileX, tileY, 2,
            1, 1, 1,
            0, 0, 0,
            0);    
    
    objectsContext->addObject(exit);
}

DMMapGenerator::~DMMapGenerator() {
}

