/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMCreditsController.cpp
 * Author: demensdeum
 * 
 * Created on April 17, 2017, 11:46 PM
 */

#include "DMCreditsController.h"

#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>

DMCreditsController::DMCreditsController() {
    
}

DMCreditsController::DMCreditsController(const DMCreditsController& orig) {
}

void DMCreditsController::beforeStart() {
    
    auto demensdeumLogo = std::make_shared<FSEObject>();
    
    auto model = FSEGTFactory::makeModelComponent(std::make_shared<string>("./data/graphics/models/cube/cube.bam"), 1, 1, 1);
    
    demensdeumLogo->addComponent(model);
    
    this->gameData->getGameObjects()->addObject(demensdeumLogo);    
}

void DMCreditsController::step() {
    
    renderer->render(this->gameData);
    
}

DMCreditsController::~DMCreditsController() {
}
