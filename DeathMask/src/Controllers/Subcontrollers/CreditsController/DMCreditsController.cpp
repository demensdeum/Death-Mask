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

#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>

static shared_ptr<FSCObject> cameraObject;

DMCreditsController::DMCreditsController() {
    
    stepCounter = 0;
    
}

DMCreditsController::DMCreditsController(const DMCreditsController& orig) {
}

void DMCreditsController::beforeStart() {
  
    cameraObject = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("camera"),
            make_shared<string>("game camera"),
            make_shared<string>(),
            make_shared<string>(),
            0, 0, 3,
            1, 1, 1,
            0, 0, 0,
            0);
    
    auto demensdeumLogo = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("scene object"),
            make_shared<string>("demensdeum logo"),
            make_shared<string>(),
            make_shared<string>("./data/graphics/models/demensdeumLogo/demensdeumLogo"),
            0, 0, 0,
            1, 1, 1,
            0, 0, 0,
            0);
    
    objectsContext->addObject(cameraObject);    
    objectsContext->addObject(demensdeumLogo);   
}

void DMCreditsController::step() {
     
    if (stepCounter < 100) {
    
    auto cameraRotation = FSEGTUtils::getObjectRotation(cameraObject);
    
    cameraRotation->z += 0.4;
    
    renderer->render(gameData);
        
        
        stepCounter++;
        
    }
    else {
        
        objectsContext->removeAllObjects();
        
        this->notifyListenerAboutControllerDidFinish(this);
        
    }
    
}

DMCreditsController::~DMCreditsController() {
}

