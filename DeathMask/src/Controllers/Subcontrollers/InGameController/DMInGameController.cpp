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

#include <FlameSteelEngine/FSEMessage.h>
#include <FlameSteelEngine/FSEUtils.h>

#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>

#include <DeathMask/src/Algorithms/MapGenerator/DMMapGenerator.h>
#include <DeathMask/src/Algorithms/MapGenerator/DMMapGeneratorParams.h>

#include <DeathMask/src/Data/GameMap/DMGameMap.h>

#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>

#include <iostream>

using namespace std;

DMInGameController::DMInGameController() {
}

DMInGameController::DMInGameController(const DMInGameController& orig) {
}

void DMInGameController::beforeStart() {

    this->generateMap();
}

void DMInGameController::generateMap() {

    objectsContext->removeAllObjects();

    auto mapGenerator = std::make_shared<DMMapGenerator>();

    auto mapGeneratorParams = std::make_shared<DMMapGeneratorParams>();

    mapGeneratorParams->freeTileIndex = 0;
    mapGeneratorParams->solidTileIndex = 1;

    mapGeneratorParams->maxIterations = 255;
    mapGeneratorParams->minCursorSize = 2;
    mapGeneratorParams->maxCursorSize = 1 + FSEUtils::FSERandomInt(6);
    mapGeneratorParams->maxLineLength = 6 + FSEUtils::FSERandomInt(6);

    mapGeneratorParams->gameplayObjectRespawnChance = 10;

    gameData->gameMap = std::make_shared<DMGameMap>();

    mapGenerator->generate(mapGeneratorParams, gameData->gameMap, this->objectsContext);

    for (auto x = 0; x < gameData->gameMap->width; x++) {

        for (auto y = 0; y < gameData->gameMap->height; y++) {

            auto tileIndex = gameData->gameMap->getTileIndexAtXY(x, y);

            if (tileIndex == 0) {

                auto floor = FSEGTFactory::makeOnSceneObject(
                        std::make_shared<string>("scene object"),
                        std::make_shared<string>("floor"),
                        std::make_shared<string>(),
                        std::make_shared<string>("./data/graphics/models/floor/floor"),
                        x, y, 1,
                        1, 1, 1,
                        0, 0, 0,
                        0);

                objectsContext->addObject(floor);
            } else if (tileIndex == 1) {

                auto wall = FSEGTFactory::makeOnSceneObject(
                        std::make_shared<string>("scene object"),
                        std::make_shared<string>("wall"),
                        std::make_shared<string>(),
                        std::make_shared<string>("./data/graphics/models/wall/wall"),
                        x, y, 2,
                        1, 1, 1,
                        0, 0, 0,
                        0);

                objectsContext->addObject(wall);
            }
        }
    }
    
    auto inventoryPrint = FSEGTFactory::makeOnSceneObject(
            std::make_shared<string>("ui"),
            std::make_shared<string>("inventory print"),
            std::make_shared<string>(),
            std::make_shared<string>(),
            0, 0, 0,
            0.07, 1, 0.07,
            0, 0, 0,
            0);

    FSEGTUtils::setText(std::make_shared<string>("test"), inventoryPrint);
    
    objectsContext->addObject(inventoryPrint);    
}

shared_ptr<FSEObject> DMInGameController::getExitObject() {

    auto gameObjects = this->getGameData()->getGameObjects();

    for (int i = 0; i < gameObjects->size(); i++) {

        auto gameObject = gameObjects->objectAtIndex(i);

        if (gameObject->getInstanceIdentifier().get()->compare("exit") == 0) {

            exitObject = gameObject;

            break;
        }
    }

    return exitObject;
    
}

shared_ptr<FSEObject> DMInGameController::getRevilObject() {

    auto gameObjects = this->getGameData()->getGameObjects();

    for (int i = 0; i < gameObjects->size(); i++) {

        auto gameObject = gameObjects->objectAtIndex(i);

        if (gameObject->getInstanceIdentifier().get()->compare("revil") == 0) {

            revilObject = gameObject;

            break;
        }
    }

    return revilObject;

}

void DMInGameController::step() {

    // handle controller message

    auto message = this->getControllerMessage();

    if (message.get() != nullptr) {

        this->generateMap();

        this->clearMessage();

    }
    else {

        if (ioSystem->inputController->isExitKeyPressed()) {

            cout << "Bye-Bye!" << endl;

            exit(0);
        }
        
        if (ioSystem->inputController->isDownKeyPressed()) {

            auto revilObject = getRevilObject();

            if (revilObject.get() == nullptr) {

                return;

            }

            auto position = FSEGTUtils::getObjectPosition(revilObject);

            position->y += 1;

            objectPickAtXY(position->x, position->y);
            
            this->objectsContext->updateObject(revilObject);
        }

        if (ioSystem->inputController->isUpKeyPressed()) {

            auto revilObject = getRevilObject();

            if (revilObject.get() == nullptr) {

                return;

            }

            auto position = FSEGTUtils::getObjectPosition(revilObject);

            position->y -= 1;
            
            objectPickAtXY(position->x, position->y);

            this->objectsContext->updateObject(revilObject);
        }

        if (ioSystem->inputController->isLeftKeyPressed()) {

            auto revilObject = getRevilObject();

            if (revilObject.get() == nullptr) {

                return;

            }

            auto position = FSEGTUtils::getObjectPosition(revilObject);

            position->x -= 1;
            
            objectPickAtXY(position->x, position->y);

            this->objectsContext->updateObject(revilObject);
        }

        if (ioSystem->inputController->isRightKeyPressed()) {

            auto revilObject = getRevilObject();

            if (revilObject.get() == nullptr) {

                return;

            }

            auto position = FSEGTUtils::getObjectPosition(revilObject);

            position->x += 1;
            
            objectPickAtXY(position->x, position->y);

            this->objectsContext->updateObject(revilObject);
        }

        // check map exit case

        auto revilObject = this->getRevilObject();
        auto exitObject = this->getExitObject();

        auto revilPosition = FSEGTUtils::getObjectPosition(revilObject);
        auto exitPosition = FSEGTUtils::getObjectPosition(exitObject);

        if (revilPosition->x == exitPosition->x &&
                revilPosition->y == exitPosition->y) {

            this->setControllerMessage(std::make_shared<FSEMessage>(std::make_shared<string>("Generate New Map"), shared_ptr<string>()));
        }

        ioSystem->inputController->clearKeys();

        renderer->render(gameData);
    }
}

void DMInGameController::objectPickAtXY(int x, int y) {
    
    auto gameMap = std::static_pointer_cast<DMGameMap>(gameData->gameMap);    
    
    auto objectId = gameMap->objectIdAtXY(x, y);
    
    if (objectId != DMGameMapNoObjectId) {
        
        auto object = this->gameData->getGameObjects()->objectWithId(objectId);
        
        if (object.get() != nullptr) {
            
            auto instanceIdentifier = object->getInstanceIdentifier();
            
            if (instanceIdentifier->compare("crate") == 0) {
                                
                pickRandomItem();
            }
        }
    }
}

void DMInGameController::pickRandomItem() {
    
    cout << "Got random item" << endl;
}

DMInGameController::~DMInGameController() {

    cout << "DMInGameController Destroyed" << endl;

}

