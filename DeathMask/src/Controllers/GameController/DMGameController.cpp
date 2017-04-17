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

#include <FlameSteelEngineGameToolkitDesktop/IOSystems/Desktop/FSEGTIODesktopSystem.h>
#include <FlameSteelEngineGameToolkit/IOSystems/SDL/FSEGTIOGenericSystemParams.h>
#include <FlameSteelEngine/FSEUtils.h>

#include <DeathMask/src/Const/DMConstIOSystem.h>

DMGameController::DMGameController() {
    
    // IO System
    
    auto ioSystemParams = shared_ptr<FSEGTIOGenericSystemParams>(new FSEGTIOGenericSystemParams());
    ioSystemParams->title = FSEUtils::localizedString(std::make_shared<string>("Bad Robots"));
    ioSystemParams->width = DMConstIOSystemScreenWidth;
    ioSystemParams->height = DMConstIOSystemScreenHeight;
    
    ioSystem = this->makeIOSystem();
    ioSystem->initialize();
}

shared_ptr<FSEGTIOSystem> DMGameController::makeIOSystem() {
    
#ifdef __EMSCRIPTEN__

    auto ioSystem = shared_ptr<FSEGTIOWebSystem>(new FSEGTIOWebSystem());
    
#else
    
    auto ioSystem = std::make_shared<FSEGTIODesktopSystem>();    
    
#endif    
    
    return ioSystem;
}

DMGameController::DMGameController(const DMGameController& orig) {
}

void DMGameController::controllerDidFinish(FSEGTController *controller) {
    
}

DMGameController::~DMGameController() {
}

