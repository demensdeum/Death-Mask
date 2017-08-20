/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMInGameController.cpp
 * Author: demensdeum
 * 
 * Created on April 26, 2017, 8:42 AM
 */

#include "DMInGameController.h"
#include "FlameSteelEngineGameToolkit/IO/Input/FSEGTInputController.h"

#include <FlameSteelCore/FSCMessage.h>

#include <FlameSteelSpiderToolkit/FSSTUDPSender.h>

#include <iostream>

using namespace std;

DMInGameController::DMInGameController() {
    
    inGameObjectsController = make_shared<DMInGameObjectsController>();
    inGameSceneController = make_shared<DMInGameSceneController>();
    inGameUIController = make_shared<DMInGameUIController>();
}

DMInGameController::DMInGameController(const DMInGameController& orig) {
}

void DMInGameController::initializeSubcontroller(shared_ptr<FSEGTController> subcontroller) {
    
    subcontroller->setIOSystem(ioSystem);
    subcontroller->setGameData(gameData);
    subcontroller->objectsContext = objectsContext;    
    
    subcontroller->beforeStart();
}

void DMInGameController::beforeStart() {

    initializeSubcontroller(inGameObjectsController);
    initializeSubcontroller(inGameSceneController);
    initializeSubcontroller(inGameUIController);
    
    inGameSceneController->generateMap();
}

void DMInGameController::step() {
    
    // handle controller message

    auto message = inGameObjectsController->getControllerMessage();

    if (message.get() != nullptr) {

        inGameSceneController->generateMap();

        inGameObjectsController->clearMessage();

    } else {

        ioSystem->inputController->pollKey();

        if (ioSystem->inputController->isExitKeyPressed()) {

            cout << "Bye-Bye!" << endl;

            FSSTUDPSender::sendStringToDefault(make_shared<string>("Bye-Bye!"));

            exit(0);
        }

        inGameObjectsController->step();
        inGameUIController->step();
        
        ioSystem->inputController->clearKeys();

        renderer->render(gameData);
    }
}

DMInGameController::~DMInGameController() {

    cout << "DMInGameController Destroyed" << endl;

}

