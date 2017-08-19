/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMInGameUIController.cpp
 * Author: demensdeum
 * 
 * Created on August 19, 2017, 11:34 AM
 */

#include "DMInGameUIController.h"
#include "DeathMask/src/Utils/DMUtils.h"

#include <FlameSteelSpiderToolkit/FSSTUDPSender.h>

#include <sstream>

DMInGameUIController::DMInGameUIController() {
}

DMInGameUIController::DMInGameUIController(const DMInGameUIController& orig) {
}

void DMInGameUIController::step() {
    
    renderUI();
    
}

void DMInGameUIController::renderUI() {
    
    auto revilObject = getRevilObject();
    
    if (revilObject == nullptr) {
        
        return;
                
    }
    
    auto gameplayProperties = DMUtils::getGameplayProperties(revilObject);
    
    if (gameplayProperties.get() == nullptr) {
        
        return;
        
    }
    
    ostringstream uiString;
        
    uiString << endl << "---Stats---" << endl << "Hunger: " << gameplayProperties->getHunger() << endl;
    
    FSSTUDPSender::sendStringToDefault(make_shared<string>(uiString.str().c_str()));
    
}

shared_ptr<FSCObject> DMInGameUIController::getRevilObject() {

    auto gameObjects = getGameData()->getGameObjects();

    for (int i = 0; i < gameObjects->size(); i++) {

        auto gameObject = gameObjects->objectAtIndex(i);

        if (gameObject->getInstanceIdentifier().get()->compare("revil") == 0) {

            return gameObject;

            break;
        }
    }

    return shared_ptr<FSCObject>();

}

DMInGameUIController::~DMInGameUIController() {
}

