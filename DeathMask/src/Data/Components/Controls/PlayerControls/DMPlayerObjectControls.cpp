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

	auto step = 0.4;

    auto position = FSEGTUtils::getObjectPosition(object);
      
    if (inputController->isLeftKeyPressed()) {

        position->x -= step;
        
    }

    if (inputController->isRightKeyPressed()) {

        position->x += step;
        
    }
  
    if (inputController->isDownKeyPressed()) {    

        position->z += step;
        
    }

    if (inputController->isUpKeyPressed()) {

        position->z -= step;
        
    }

    delegate->objectsControlsDelegateObjectDidUpdate(object);
}

DMPlayerObjectControls::~DMPlayerObjectControls() {
}

