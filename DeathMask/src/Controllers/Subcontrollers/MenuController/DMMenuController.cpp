/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMMenuController.cpp
 * Author: demensdeum
 * 
 * Created on July 1, 2017, 8:18 AM
 */

#include "DMMenuController.h"

#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>

DMMenuController::DMMenuController() {
    
    stepCounter = 0;
    
}

DMMenuController::DMMenuController(const DMMenuController& orig) {
}

void DMMenuController::beforeStart() {
    
    auto cameraObject = FSEGTFactory::makeOnSceneObject(
            std::make_shared<string>("camera"),
            std::make_shared<string>("game camera"),
            std::make_shared<string>(),
            std::make_shared<string>(),
            0, 4, 0,
            1, 1, 1,
            0, 0, 0,
            0);    
    
    auto menu = FSEGTFactory::makeOnSceneObject(
            std::make_shared<string>("scene object"),
            std::make_shared<string>("menu"),
            std::make_shared<string>(),
            std::make_shared<string>("./data/graphics/models/menu/menu"),
            0, 0, 0,
            1, 1, 1,
            0, 0, 0,
            0);    
    
    objectsContext->addObject(cameraObject);      
    objectsContext->addObject(menu);
    
}

void DMMenuController::step() {
    
    renderer->render(this->gameData);
    
    if (stepCounter < 100) {
        
        stepCounter++;
        
    }
    else {
        
        objectsContext->removeAllObjects();
        
        this->notifyListenerAboutControllerDidFinish(this);
        
    }    
}

DMMenuController::~DMMenuController() {
}

