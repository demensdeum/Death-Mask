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

#include <ctime>

#include <FlameSteelEngineGameToolkit/IO/IOSystems/FSEGTIOGenericSystemParams.h>

#include <FlameSteelCore/FSCUtils.h>

#include <DeathMask/src/Const/DMConstStates.h>
#include <DeathMask/src/Const/DMConstIOSystem.h>

#include <DeathMask/src/Controllers/Subcontrollers/InGameController/DMInGameController.h>


#define DEATHMASK_IO_SYSTEM 0

#if DEATHMASK_IO_SYSTEM == 0
#include <FlameSteelEngineGameToolkitFSGL/FSEGTIOFSGLSystem.h>
#elif DEATHMASK_IO_SYSTEM ==1
#include <FlameSteelEngineGameToolkitNcurses/FSEGTIONcursesSystem.h>
#endif

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
        
    auto inGameController = make_shared<DMInGameController>();
    this->setControllerForState(inGameController, DMStateInGame);
}

shared_ptr<FSEGTIOSystem> DMGameController::makeIOSystem() {

#if DEATHMASK_IO_SYSTEM == 0
    auto ioSystem = make_shared<FSEGTIOFSGLSystem>();    
#elif DEATHMASK_IO_SYSTEM ==1
    auto ioSystem = make_shared<FSEGTIONcursesSystem>();    
#endif    

    return ioSystem;
}

void DMGameController::controllerDidFinish(FSEGTController *) {
    
    switch (state) {
     
        case DMStateMenu:
            
            switchToState(DMStateInGame);
            
            break; 
           
    }
}

DMGameController::DMGameController(const DMGameController& ) {
}

DMGameController::~DMGameController() {
}