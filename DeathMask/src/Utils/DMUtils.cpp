/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMUtils.cpp
 * Author: demensdeum
 * 
 * Created on August 19, 2017, 5:08 PM
 */

#include "DMUtils.h"

#include <DeathMask/src/Const/DMConstTypes.h>

DMUtils::DMUtils() {
}

DMUtils::DMUtils(const DMUtils& ) {
}

void DMUtils::incrementHungerForObject(shared_ptr<FSCObject> object) {
    
    auto gameplayProperties = DMUtils::getGameplayProperties(object);
    
    if (gameplayProperties.get() == nullptr) {
        
        return;
        
    }
    
    gameplayProperties->incrementHunger();
    
}

shared_ptr<DMTileProperties> DMUtils::getTileProperties(shared_ptr<FSCObject> tile) {

	if (tile.get() == nullptr) {

		return shared_ptr<DMTileProperties>();

	}

	auto tileProperties = tile->getComponent(make_shared<string>(DMConstTypesTileProperties));

	auto castedTileProperties = static_pointer_cast<DMTileProperties>(tileProperties);

	return castedTileProperties;
}

void DMUtils::decrementHealthIfNeeded(shared_ptr<FSCObject> object) {
    
    auto gameplayProperties = DMUtils::getGameplayProperties(object);
    
    if (gameplayProperties.get() == nullptr) {
        
        return;
        
    }
    
    auto hunger = gameplayProperties->getHunger();
    
    if (hunger >= 10) {
    
        gameplayProperties->decrementHealth();  
        
    }
}

shared_ptr<DMGameplayProperties> DMUtils::getGameplayProperties(shared_ptr<FSCObject> object) {
    
    auto gameplayProperties = object->getComponent(make_shared<string>("death mask gameplay properties"));
    
    auto castedGameplayProperties = static_pointer_cast<DMGameplayProperties>(gameplayProperties);
    
    return castedGameplayProperties;
    
}

shared_ptr<DMObjectControls> DMUtils::getObjectControls(shared_ptr<FSCObject> object) {
    
    auto objectControls = object->getComponent(make_shared<string>("object controls"));
    
    auto castedObjectControls = static_pointer_cast<DMObjectControls>(objectControls);
    
    return castedObjectControls;
}

void DMUtils::step(shared_ptr<FSCObject> object, shared_ptr<DMObjectControlsDelegate> delegate) {
    
    auto objectControls = getObjectControls(object);
    
    if (objectControls.get() == nullptr) {
        
        return;
        
    }
    
    objectControls->step(delegate);
}

DMUtils::~DMUtils() {
}
