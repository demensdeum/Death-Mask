/*
 * FSEGTGameData.cpp
 *
 *  Created on: Jul 31, 2016
 *      Author: demensdeum
 */

#include "FSEGTGameData.h"
#include <cstddef>

#include <FlameSteelEngineGameToolkit/Data/Components/Vector/FSEGTVector.h>
#include "FlameSteelEngineGameToolkit/Const/FSEGTConst.h"

#include <memory>

using namespace std;

FSEGTGameData::FSEGTGameData() {
    
	gameObjects = make_shared<FSCObjects>();
        
}

shared_ptr<FSCObjects> FSEGTGameData::getGameObjects() {
	return this->gameObjects;
}

FSEGTGameData::~FSEGTGameData() {
	// TODO Auto-generated destructor stub
}
