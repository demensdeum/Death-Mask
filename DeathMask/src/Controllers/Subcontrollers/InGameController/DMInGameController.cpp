/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMGameController.cpp
 * Author: demensdeum
 * 
 * Created on April 25, 2017, 8:40 AM
 */

#include "DMInGameController.h"

DMInGameController::DMInGameController() {
}

DMInGameController::DMInGameController(const DMInGameController& orig) {
}

void DMInGameController::beforeStart() {
    
}

void DMInGameController::step() {
    
    renderer->render(this->gameData);
    
}

DMInGameController::~DMInGameController() {
}

