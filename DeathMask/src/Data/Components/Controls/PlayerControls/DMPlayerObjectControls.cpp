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

	bool updateNeeded = false;

	auto step = 0.4;

	auto position = FSEGTUtils::getObjectPosition(object);
      
	if (inputController->isLeftKeyPressed()) {

		position->x -= step;
		updateNeeded = true;        

	}

	if (inputController->isRightKeyPressed()) {

		position->x += step;
		updateNeeded = true;        

	}
  
	if (inputController->isDownKeyPressed()) {    

		position->z += step;
		updateNeeded = true;
	}

	if (inputController->isUpKeyPressed()) {

		position->z -= step;
		updateNeeded = true;        
	}

	if (updateNeeded)
	{
		delegate->objectsControlsDelegateObjectDidUpdate(object);
	}
}

DMPlayerObjectControls::~DMPlayerObjectControls() {
}

