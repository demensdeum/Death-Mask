/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMGameController.cpp
 * Author: demensdeum
 * 
 * Created on April 16, 2017, 5:58 PM
 */

#include "DMGameController.h"
#include "DeathMask/src/Controllers/Subcontrollers/InGameController/DMInGameController.h"
#include "DeathMask/src/Controllers/Subcontrollers/MenuController/DMMenuController.h"

#include <ctime>

#include <FlameSteelEngineGameToolkit/IO/IOSystems/FSEGTIOGenericSystemParams.h>

#include <FlameSteelCore/FSCUtils.h>

#include <DeathMask/src/Const/DMConstStates.h>
#include <DeathMask/src/Const/DMConstIOSystem.h>

#include <DeathMask/src/Controllers/Subcontrollers/CreditsController/DMCreditsController.h>
#include <DeathMask/src/Controllers/Subcontrollers/InGameController/DMInGameController.h>

#include <DeathMask/src/IO/IOSystems/FlameSteelEngineGameToolkitFSGL/FSEGTIOFSGLSystem.h>

DMGameController::DMGameController() {
    
    // random seed
    
    srand (time(NULL));
    
    // IO System
    
    auto ioSystemParams = make_shared<FSEGTIOGenericSystemParams>();
    ioSystemParams->title = FSCUtils::localizedString(make_shared<string>("Death Mask"));
    ioSystemParams->width = DMConstIOSystemScreenWidth;
    ioSystemParams->height = DMConstIOSystemScreenHeight;
    
    ioSystem = this->makeIOSystem();
    ioSystem->initialize();
    
    auto creditsController = make_shared<DMCreditsController>();
    this->setControllerForState(creditsController, DMStateCredits);  
        
    auto inGameController = make_shared<DMInGameController>();
    this->setControllerForState(inGameController, DMStateInGame);
    
    auto menuController = make_shared<DMMenuController>();
    this->setControllerForState(menuController, DMStateMenu);
}

shared_ptr<FSEGTIOSystem> DMGameController::makeIOSystem() {
    
    auto ioSystem = make_shared<FSEGTIOFSGLSystem>();    
    
    return ioSystem;
}

void DMGameController::controllerDidFinish(FSEGTController *controller) {
    
    switch (state) {
     
        case DMStateCredits:
            
            switchToState(DMStateMenu);
            
            break; 
            
        case DMStateMenu:
            
            switchToState(DMStateInGame);
            
            break;
    }
}

DMGameController::DMGameController(const DMGameController& orig) {
}

DMGameController::~DMGameController() {
}

