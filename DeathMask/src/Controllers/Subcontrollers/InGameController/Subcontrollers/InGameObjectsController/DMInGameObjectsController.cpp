/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InGameObjectsController.cpp
 * Author: demensdeum
 * 
 * Created on August 19, 2017, 11:44 AM
 */

#include "DMInGameObjectsController.h"

#include <DeathMask/src/Utils/DMUtils.h>
#include <DeathMask/src/Data/GameMap/DMGameMap.h>

#include <FlameSteelEngineGameToolkit/IO/Input/FSEGTInputController.h>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <iostream>

#include <FlameSteelSpiderToolkit/FSSTUDPSender.h>

DMInGameObjectsController::DMInGameObjectsController() {

    roundCounter = 0;
    
    auto thisSharedPointer = shared_from_this();
    
    objectControlsDelegate = static_pointer_cast<DMObjectControlsDelegate>(thisSharedPointer);
}

DMInGameObjectsController::DMInGameObjectsController(const DMInGameObjectsController& orig) {
}

void DMInGameObjectsController::pickRandomItem() {

    cout << "Got random item" << endl;
}

void DMInGameObjectsController::step() {

    roundCounter += 1;

    if (roundCounter > 10) {
        
        allObjectsIncrementHunger();
        
        roundCounter = 0;
        
    }
    
    auto gameObjects = gameData->getGameObjects();
    
    for (int i = 0; i < gameObjects->size(); i++) {
        
        auto object = gameObjects->objectAtIndex(i);
        
        DMUtils::step(object, objectControlsDelegate);
        
    }

    // update camera position

    {
        auto cameraObject = getCameraObject();
        auto revilObject = getRevilObject();

        auto revilPosition = FSEGTUtils::getObjectPosition(revilObject);

        auto cameraPosition = FSEGTUtils::getObjectPosition(cameraObject);
        auto cameraRotation = FSEGTUtils::getObjectRotation(cameraObject);

        cameraPosition->x = revilPosition->x;
        cameraPosition->y = 10.f;
        cameraPosition->z = revilPosition->y + 3.f;

        cameraRotation->x = 5.f;
        cameraRotation->y = 0;
        cameraRotation->z = 0;

        this->objectsContext->updateObject(cameraObject);
    }

    // check map exit case

    auto revilObject = this->getRevilObject();
    auto exitObject = this->getExitObject();

    auto revilPosition = FSEGTUtils::getObjectPosition(revilObject);
    auto exitPosition = FSEGTUtils::getObjectPosition(exitObject);

    if (revilPosition->x == exitPosition->x &&
            revilPosition->y == exitPosition->y) {

        this->setControllerMessage(make_shared<FSCMessage>(make_shared<string>("Generate New Map"), shared_ptr<string>()));
        
    }

}

void DMInGameObjectsController::objectsControlsDelegateObjectDidUpdate(shared_ptr<FSCObject> object) {
    
    objectsContext->updateObject(object);
    
}

void DMInGameObjectsController::allObjectsIncrementHunger() {
    
    auto gameObjects = gameData->getGameObjects();
    
    if (gameObjects.get() == nullptr) {
        
        return;
        
    }
    
    for (auto i = 0; i < gameObjects->size(); i++) {
        
        auto object = gameObjects->objectAtIndex(i);
        
        DMUtils::incrementHungerForObject(object);
    }
}

void DMInGameObjectsController::objectPickAtXY(int x, int y) {

    auto gameMap = std::static_pointer_cast<DMGameMap>(gameData->gameMap);

    auto objectId = gameMap->objectIdAtXY(x, y);

    if (objectId != DMGameMapNoObjectId) {

        auto object = this->gameData->getGameObjects()->objectWithId(objectId);

        if (object.get() != nullptr) {

            auto instanceIdentifier = object->getInstanceIdentifier();

            if (instanceIdentifier->compare("crate") == 0) {

                pickRandomItem();

            } else if (instanceIdentifier->compare("mask") == 0) {

                cout << "You have found mask!" << endl;

                FSSTUDPSender::sendStringToDefault(make_shared<string>("You have found mask!"));

            }
        }
    }
}

shared_ptr<FSCObject> DMInGameObjectsController::getExitObject() {

    auto gameObjects = this->getGameData()->getGameObjects();

    for (int i = 0; i < gameObjects->size(); i++) {

        auto gameObject = gameObjects->objectAtIndex(i);

        if (gameObject->getInstanceIdentifier().get()->compare("exit") == 0) {

            return gameObject;
        }
    }

    return shared_ptr<FSCObject>();

}

shared_ptr<FSCObject> DMInGameObjectsController::getCameraObject() {

    auto gameObjects = this->getGameData()->getGameObjects();

    for (int i = 0; i < gameObjects->size(); i++) {

        auto gameObject = gameObjects->objectAtIndex(i);

        if (gameObject->getInstanceIdentifier().get()->compare("game camera") == 0) {

            return gameObject;
        }
    }

    return shared_ptr<FSCObject>();

}

shared_ptr<FSCObject> DMInGameObjectsController::getRevilObject() {

    auto gameObjects = this->getGameData()->getGameObjects();

    for (int i = 0; i < gameObjects->size(); i++) {

        auto gameObject = gameObjects->objectAtIndex(i);

        if (gameObject->getInstanceIdentifier().get()->compare("revil") == 0) {

            return gameObject;

            break;
        }
    }

    return shared_ptr<FSCObject>();

}

DMInGameObjectsController::~DMInGameObjectsController() {
}

