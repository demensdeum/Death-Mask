/*
 * FSEGTIOSystem.cpp
 *
 *  Created on: Aug 21, 2016
 *      Author: demensdeum
 */

#include "FSEGTIOSystem.h"

FSEGTIOSystem::FSEGTIOSystem() {

}

void FSEGTIOSystem::clearCache() {

	resourcesManager->clear();
}

void FSEGTIOSystem::initialize(shared_ptr<FSEGTIOSystemParams> ) {

}

FSEGTIOSystem::~FSEGTIOSystem() {
	// TODO Auto-generated destructor stub
}
