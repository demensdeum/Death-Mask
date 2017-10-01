/*
 * FSCObjects.cpp
 *
 *  Created on: Jul 31, 2016
 *      Author: demensdeum
 */

#include "FSCObjects.h"

#include <cstddef>

FSCObjects::FSCObjects() {
    
}

void FSCObjects::addObject(shared_ptr<FSCObject> object) {
    
    objects.push_back(object);
    
    idToObject[object->id] = object;
}

shared_ptr<FSCObject> FSCObjects::objectWithId(int id) {
    
    return idToObject[id];
    
}

shared_ptr<FSCObject> FSCObjects::objectAtIndex(unsigned int index) {
	if (index >= objects.size()) {
		return shared_ptr<FSCObject>();
	}

	return objects[index];
}

int FSCObjects::size() {
	return objects.size();
}

vector <shared_ptr<FSCObject> >* FSCObjects::getObjectsVector() {
    
    return &objects;
}

void FSCObjects::removeObjectAtIndex(unsigned int index) {
	if (index < objects.size()) {
		objects.erase(objects.begin() + index);
	}
}

void FSCObjects::removeAllObjects() {

    for (unsigned int i = 0; i < objects.size(); i++) {
        
        i--;
        objects.pop_back();
        
    }
    
}

FSCObjects::~FSCObjects() {
	// TODO Auto-generated destructor stub
}
