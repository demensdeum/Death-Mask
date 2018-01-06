/*
 * FSEGTGameController.cpp
 *
 *  Created on: Jul 27, 2016
 *      Author: demensdeum
 */

#include "FSEGTGameController.h"

#define FSEGT_DEBUG_PRINT_ENABLED 0
#define FSEGT_DEBUG_SHOW_FPS 0

#include <chrono>
#include <thread>
#include <iostream>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

using namespace std;

static const int FSEGTGameControllerFpsLock = 60;
static const float FSEGTGameControllerStepTimePerSecond = 1.0 / FSEGTGameControllerFpsLock; // one second / fps lock

FSEGTGameController::FSEGTGameController() {
    
    resourcesManager = make_shared<FSCResourcesManager>();
    resourcesLoader = make_shared<FSCResourcesLoader>();

    isRunning = false;
    currentController = shared_ptr<FSEGTController>();
    gameControllerMessage = shared_ptr<FSCMessage>();
    gameData = shared_ptr<FSEGTGameData>();

    printedSelf = false;
    
#ifdef __EMSCRIPTEN__
    GLOBAL_fsegt_emscripten_gameController = this;
#endif
}

#ifdef __EMSCRIPTEN__

void GLOBAL_fsegt_emscripten_gameLoop() {
    // oh god I don't like javascript for some ugly decisions like those

    GLOBAL_fsegt_emscripten_gameController->gameLoop();
}
#endif

void FSEGTGameController::startGameFromState(int startState) {

    gameData = make_shared<FSEGTGameData>();

    objectsContext = make_shared<FSEGTObjectsContext>();
    objectsContext->objects = gameData->getGameObjects();

    objectsContext->subscribe(ioSystem);
    
    this->beforeStart();

    this->switchToState(startState);

    this->setIsRunning(true);

#ifndef __EMSCRIPTEN__
    this->gameLoop();
#else
    emscripten_set_main_loop(GLOBAL_fsegt_emscripten_gameLoop, 60, 1);
#endif    

}

void FSEGTGameController::setIOSystem(shared_ptr<FSEGTIOSystem> ioSystem) {

    ioSystem->resourcesManager = this->resourcesManager;

    this->ioSystem = ioSystem;
}

void FSEGTGameController::setControllerForState(shared_ptr<FSEGTController> controller, int state) {

    stateToControllerMap[state] = controller;

}

void FSEGTGameController::switchToState(int state) {

    this->state = state;
    
    shared_ptr<FSEGTController> controller = stateToControllerMap[state];

    if (controller.get() == nullptr) {

        cout << "Cannot get controller for state: " << state << endl;

        exit(1);
    }

    cout << "Switch controller to state: " << state << endl;
    
    setCurrentController(controller);
}

void FSEGTGameController::gameLoop() {

#ifndef __EMSCRIPTEN__
    while (true) {
#endif
        clock_t begin = clock();

        this->pollGameControllerMessage();

#ifndef __EMSCRIPTEN__
        if (this->isRunning == false) {
            break; // exit
        }
#endif

        if (this->currentController.get() != nullptr) {
            
            this->step();
            
        } else {

            //cout << "FSEGTGameController: no current controller to make a step. Quit." << endl;
            
            if (printedSelf == false) {
            
                printedSelf = true;
                
            cout << this << endl;
            }
            
            exit(3);
        }

        clock_t end = clock();

        int timeSpentClicks = end - begin;
        float timeSpentSeconds = ((float) timeSpentClicks) / CLOCKS_PER_SEC;

#if FSEGT_DEBUG_SHOW_FPS
        float fps = 1 / timeSpentSeconds;

        printf("fps: %f\n", fps);
#endif            

#if FSEGT_DEBUG_PRINT_ENABLED
        printf("It took me %d clicks (%f seconds).\n", timeSpentClicks, timeSpentSeconds);
#endif

        float sleepForMsFloat = FSEGTGameControllerStepTimePerSecond - timeSpentSeconds;

        int sleepForMs = sleepForMsFloat * 1000;

#if FSEGT_DEBUG_PRINT_ENABLED
        printf("sleepForMs: %d\n", sleepForMs);
#endif        

        std::chrono::milliseconds dura(sleepForMs);

        std::this_thread::sleep_for(dura);

#ifndef __EMSCRIPTEN__                
    }
#endif
}

void FSEGTGameController::step() {
    
    this->currentController->step();
    
}

void FSEGTGameController::pollGameControllerMessage() {
    //TODO handle message
    if (this->gameControllerMessage) {

        this->handleGameControllerMessage(gameControllerMessage);

    }

    this->gameControllerMessage = shared_ptr<FSCMessage>();
}

void FSEGTGameController::setIsRunning(bool isRunning) {
    this->isRunning = isRunning;
}

void FSEGTGameController::handleGameControllerMessage(shared_ptr<FSCMessage> ) {

}

void FSEGTGameController::setGameControllerMessage(shared_ptr<FSCMessage> message) {
    this->gameControllerMessage = message;
}

void FSEGTGameController::setCurrentController(shared_ptr<FSEGTController> newCurrentController) {
    
    if (currentController.get() != newCurrentController.get()) {
        
        if (currentController.get() != nullptr) {

            currentController->beforeStop();
        }

        currentController = newCurrentController;
        currentController->setIOSystem(this->ioSystem);
        currentController->setGameData(this->getGameData());
        currentController->objectsContext = objectsContext;
        currentController->setGameController(this);
        currentController->listener = this;
        currentController->beforeStart();
    }
}

FSEGTGameController::~FSEGTGameController() {
    stateToControllerMap.clear();
}