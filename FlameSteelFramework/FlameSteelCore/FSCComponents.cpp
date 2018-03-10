/*
 * FSCComponents.cpp
 *
 *  Created on: Aug 20, 2016
 *      Author: demensdeum
 */

#include "FSCComponents.h"
#include <iostream>

FSCComponents::FSCComponents() {
    
	// TODO Auto-generated constructor stub
    
}

/*! addComponent - get component by identifier*/

void FSCComponents::addComponent(shared_ptr<FSCObject> component) {
    
	shared_ptr<string> classIdentifier = component->getClassIdentifier();
        
        if (classIdentifier.get() == nullptr) {
            
            cout << "FSCComponents: cannot add component - component class identifier is nullptr. Quit.";
            
            exit(1);
        }
        
        //cout << "FSCComponents: Add component " << component->getInstanceIdentifier()->c_str() << endl;
        
	identifierToComponentMap[*classIdentifier.get()] = component;
}

/*! getComponent - get component by identifier*/

shared_ptr<FSCObject> FSCComponents::getComponent(shared_ptr<string> identifier) {
    
    auto component = this->identifierToComponentMap[*identifier.get()];
    
    return component;
}

/*! removeComponent - remove component by identifier*/
void FSCComponents::removeComponent(shared_ptr<string> identifier) {
    
    this->identifierToComponentMap.erase(*identifier.get());
    
}

FSCComponents::~FSCComponents() {
	// TODO Auto-generated destructor stub
}

