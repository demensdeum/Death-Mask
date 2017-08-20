/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMPlayerControls.cpp
 * Author: demensdeum
 * 
 * Created on August 20, 2017, 12:55 PM
 */

#include "DMPlayerObjectControls.h"

#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>

void DMPlayerObjectControls::step(shared_ptr<DMObjectControlsDelegate> delegate) {

    auto position = FSEGTUtils::getObjectPosition(object);
    
    auto x = position->x;
    auto y = position->y;
    
    if (inputController->isDownKeyPressed()) {    

        y += 1;
        
    }

    if (inputController->isUpKeyPressed()) {

        y -= 1;
        
    }

    if (inputController->isLeftKeyPressed()) {

        x -= 1;
        
    }

    if (inputController->isRightKeyPressed()) {

        x += 1;
        
    }

    handleTargetAt(x, y, position);

    delegate->objectsControlsDelegateObjectDidUpdate(object);
}

void DMPlayerObjectControls::handleTargetAt(int x, int y, shared_ptr<FSEGTVector> position) {
    
    position->x = x;
    position->y = y;
    
}

DMPlayerObjectControls::~DMPlayerObjectControls() {
}

