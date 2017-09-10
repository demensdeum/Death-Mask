/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMInGameOptimizedRenderingController.cpp
 * Author: demensdeum
 * 
 * Created on September 10, 2017, 1:25 PM
 */

#include "DMInGameOptimizedRenderingController.h"
#include "FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h"
#include "DeathMask/src/Data/GameMap/DMGameMap.h"

DMInGameOptimizedRenderingController::DMInGameOptimizedRenderingController() {
}

DMInGameOptimizedRenderingController::DMInGameOptimizedRenderingController(const DMInGameOptimizedRenderingController& orig) {
}

set<int> DMInGameOptimizedRenderingController::renderingIDs() {

    auto castedGameMap = static_pointer_cast<DMGameMap>(gameData->gameMap);

    set<int> ids;

    auto revilObject = getRevilObject();

    auto revilObjectID = revilObject->id;

    ids.insert(revilObjectID);

    auto centerPosition = static_pointer_cast<FSEGTVector>(FSEGTUtils::getObjectPosition(revilObject)->copy());

    // walls

    auto startPointX = centerPosition->x - 4;
    auto startPointY = centerPosition->y - 4;

    for (auto y = 0; y < 9; y++) {

        for (auto x = 0; x < 9; x++) {

            for (auto layer = 0; layer < DMGameMapMaxLayers; layer++) {


                auto objectID = castedGameMap->objectIdAtXY(startPointX + x, startPointY + y, layer);

                if (objectID != DMGameMapNoObjectId) {

                    ids.insert(objectID);

                }
            }
        }
    }

    return ids;
}

shared_ptr<FSCObject> DMInGameOptimizedRenderingController::getRevilObject() {

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

DMInGameOptimizedRenderingController::~DMInGameOptimizedRenderingController() {
}

