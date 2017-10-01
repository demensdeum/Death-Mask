/*
 * FSCComponents.h
 *
 *  Created on: Aug 20, 2016
 *      Author: demensdeum
 */

#ifndef FSCCOMPONENTS_H_
#define FSCCOMPONENTS_H_

#include "FSCObject.h"
#include <map>
#include <iostream>

using namespace std;

class FSCComponents: public FSCObject {
public:
	FSCComponents();

	/*! addComponent - add component*/
	void addComponent(shared_ptr<FSCObject> component);

	/*! getComponent - get component by identifier*/
	shared_ptr<FSCObject> getComponent(shared_ptr<string> identifier);

	/*! removeComponent - remove component by identifier*/
	void removeComponent(shared_ptr<string> identifier);

	virtual ~FSCComponents();

private: 
    
	map<string, shared_ptr<FSCObject> > identifierToComponentMap;
};

#endif /* FSCCOMPONENTS_H_ */
