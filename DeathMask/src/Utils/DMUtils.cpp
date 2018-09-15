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
#include <FlameSteelCore/Object.h>
#include <DeathMask/src/Const/DMConstClassIdentifiers.h>
#include <DeathMask/src/Data/Components/Item/ItemProperties.h>
#include <FlameSteelEngineGameToolkit/Data/Components/Text/FSEGTText.h>
#include <DeathMask/src/Data/Components/Controls/ZombieControls/ZombieControls.h>

using namespace DeathMaskGame;

DMUtils::DMUtils() {
}

DMUtils::DMUtils(const DMUtils& ) {
}

shared_ptr<ItemProperties> DMUtils::getObjectItemProperties(shared_ptr<Object> object) {

    auto itemProperties = object->getComponent(make_shared<string>(DMConstClassIdentifierItemProperties.c_str()));
    
    auto castedItemProperties = static_pointer_cast<ItemProperties>(itemProperties);
    
    return castedItemProperties;	

}

shared_ptr<FSEGTText> DMUtils::getObjectLabel(shared_ptr<Object> object) {

	auto label = object->getComponent(make_shared<string>(DMConstClassIdentifierLabel));

	auto castedText = static_pointer_cast<FSEGTText>(label);
    
	return castedText;

}

shared_ptr<DMGameplayProperties> DMUtils::getObjectGameplayProperties(shared_ptr<Object> object) {
    
    auto gameplayProperties = object->getComponent(make_shared<string>("death mask gameplay properties"));
    
    auto castedGameplayProperties = static_pointer_cast<DMGameplayProperties>(gameplayProperties);
    
    return castedGameplayProperties;
    
}

shared_ptr<DMObjectControls> DMUtils::getObjectControls(shared_ptr<Object> object) {
    
    auto objectControls = object->getComponent(make_shared<string>("object controls"));
    
    auto castedObjectControls = static_pointer_cast<DMObjectControls>(objectControls);
    
    return castedObjectControls;
}

shared_ptr<ZombieControls> DMUtils::getObjectZombieControls(shared_ptr<Object> object) {

	auto objectControls = getObjectControls(object);
	auto controlsInstanceIdentifier = objectControls->getInstanceIdentifier();
	
	if (*controlsInstanceIdentifier != string("zombie controls")) {
		throw logic_error("controls does not contain zombie controls instance identifier");
	}

	return static_pointer_cast<ZombieControls>(objectControls);
}

void DMUtils::step(shared_ptr<Object> object, shared_ptr<DMObjectControlsDelegate> delegate) {
    
    auto objectControls = getObjectControls(object);
    
    if (objectControls.get() == nullptr) {
        
        return;
        
    }
    
    objectControls->step(delegate);
}

DMUtils::~DMUtils() {
}
