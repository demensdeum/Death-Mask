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

DMCreditsController::DMCreditsController() {
}

DMCreditsController::DMCreditsController(const DMCreditsController& orig) {
}

void DMCreditsController::step() {
    
    renderer->render(this->gameData);
    
}

DMCreditsController::~DMCreditsController() {
}

