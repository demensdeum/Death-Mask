/*
 * FSCResourcesManager.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: demensdeum
 */

#include "FSCResourcesManager.h"
#include <iostream>

using namespace std;

FSCResourcesManager::FSCResourcesManager() {
	// TODO Auto-generated constructor stub

}

shared_ptr<FSCResource> FSCResourcesManager::getResourceByName(shared_ptr<string> name) {

    
    //cout << "getResourceByName: " << name->c_str() << endl;
    
	return resourcesMap[*name.get()];
}

void FSCResourcesManager::setResourceWithName(shared_ptr<string> name, shared_ptr<FSCResource> resource) {

        cout << "setResourceByName: " << name->c_str() << endl;
    
	resourcesMap[*name.get()] = resource;
}

void FSCResourcesManager::clear() {

	auto itr = resourcesMap.begin();

	if (itr != resourcesMap.end())
	{
	    resourcesMap.erase(itr);
	}
}


FSCResourcesManager::~FSCResourcesManager() {
	// TODO Auto-generated destructor stub
}

