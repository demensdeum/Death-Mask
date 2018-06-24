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
#include <FlameSteelCore/FSCObject.h>
#include <DeathMask/src/Const/DMConstClassIdentifiers.h>
#include <DeathMask/src/Data/Components/Item/ItemProperties.h>
#include <FlameSteelEngineGameToolkit/Data/Components/Text/FSEGTText.h>

DMUtils::DMUtils() {
}

DMUtils::DMUtils(const DMUtils& ) {
}

shared_ptr<ItemProperties> DMUtils::getObjectItemProperties(shared_ptr<FSCObject> object) {

    auto itemProperties = object->getComponent(make_shared<string>(DMConstClassIdentifierItemProperties.c_str()));
    
    auto castedItemProperties = static_pointer_cast<ItemProperties>(itemProperties);
    
    return castedItemProperties;	

}

shared_ptr<FSEGTText> DMUtils::getObjectLabel(shared_ptr<FSCObject> object) {

	auto label = object->getComponent(make_shared<string>(DMConstClassIdentifierLabel));

	auto castedText = static_pointer_cast<FSEGTText>(label);
    
	return castedText;

}

shared_ptr<DMGameplayProperties> DMUtils::getObjectGameplayProperties(shared_ptr<FSCObject> object) {
    
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
