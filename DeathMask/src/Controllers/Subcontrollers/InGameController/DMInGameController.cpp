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
    
    mapGenerator->generate(mapGeneratorParams);
}

void DMInGameController::step() {
    
    renderer->render(gameData);
    
}

DMInGameController::~DMInGameController() {
}

