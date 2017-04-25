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
  
    auto demensdeumLogo = FSEGTFactory::makeOnSceneObject(
            std::make_shared<string>("demensdeumLogo"),
            std::make_shared<string>("demensdeumLogo"),
            std::make_shared<string>(),
            std::make_shared<string>("./data/graphics/models/demensdeumLogo/demensdeumLogo"),
            1, 1, 1,
            0, 4, 0,
            0, 0, 0,
            0);
    
    this->gameData->getGameObjects()->addObject(demensdeumLogo);    
}

void DMCreditsController::step() {
    
    renderer->render(this->gameData);
    
}

DMCreditsController::~DMCreditsController() {
}

