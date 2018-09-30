/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMPlayerControls.cpp
 * Author: demensdeum
 * 
 * Created on August 20, 2017, 12:55 PM
 */

#include "DMPlayerObjectControls.h"

#include <glm/gtc/matrix_transform.hpp>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>

#define DMPLAYEROBJECTCONTROLSMOVEBYDIRECTION 1

void DMPlayerObjectControls::step(shared_ptr<DMObjectControlsDelegate> delegate) {

	bool updateNeeded = false;

	auto step = 0.1;

	auto position = FSEGTUtils::getObjectPosition(object);
      
	if (inputController->isLeftKeyPressed()) {

#if DMPLAYEROBJECTCONTROLSMOVEBYDIRECTION == 1
		moveByRotation(-step, 0, 0, delegate);
#else
		position->x -= step;
#endif
		updateNeeded = true;        

	}

	if (inputController->isRightKeyPressed()) {

#if DMPLAYEROBJECTCONTROLSMOVEBYDIRECTION == 1
		moveByRotation(step, 0, 0, delegate);
#else
		position->x += step;
#endif
		updateNeeded = true;        

	}
  
	if (inputController->isDownKeyPressed()) {    

#if DMPLAYEROBJECTCONTROLSMOVEBYDIRECTION == 1
		moveByRotation(0, 0, step, delegate);
#else
		position->z += step;
#endif
		updateNeeded = true;

	}

	if (inputController->isUpKeyPressed()) {

#if DMPLAYEROBJECTCONTROLSMOVEBYDIRECTION == 1
		moveByRotation(0, 0, -step, delegate);
#else
		position->z -= step;
#endif
		updateNeeded = true;

	}

	auto rotation = FSEGTUtils::getObjectRotation(object);

	if (inputController->pointerXdiff != 0)
	{
		rotation->y -= float(inputController->pointerXdiff) / 200;
	}

	if (updateNeeded)
	{
		delegate->objectsControlsDelegateObjectDidUpdate(object);
	}
}

void DMPlayerObjectControls::moveByRotation(float x, float y, float z, shared_ptr<DMObjectControlsDelegate> delegate) {

		auto position = FSEGTUtils::getObjectPosition(object)->copy();
		auto rotation = FSEGTUtils::getObjectRotation(object);

		glm::mat4 matrix(1.0);

		matrix = glm::translate(matrix, glm::vec3(position->x, position->y, position->z));

		matrix = glm::rotate(matrix, rotation->x, glm::vec3(1.f, 0.f, 0.f));
		matrix = glm::rotate(matrix, rotation->y, glm::vec3(0.f, 1.f, 0.f));
		matrix = glm::rotate(matrix, rotation->z, glm::vec3(0.f, 0.f, 1.f));

		matrix = glm::translate(matrix, glm::vec3(x, y, z));

		auto result = matrix * glm::vec4(0.f, 0.f, 0.f, 1.f);

		position->x = result.x;
		position->y = result.y;
		position->z = result.z;

	if (delegate->objectsControlsIsObjectCanMoveToPosition(shared_from_this(), object, position)) {
		FSEGTUtils::getObjectPosition(object)->populate(position);
	}
	else {
		// only x
		auto positionXonly = FSEGTUtils::getObjectPosition(object)->copy();
		positionXonly->x = position->x;
		if (delegate->objectsControlsIsObjectCanMoveToPosition(shared_from_this(), object, positionXonly)) {
			FSEGTUtils::getObjectPosition(object)->populate(positionXonly);
		}
		else {
			// only z
			auto positionZonly = FSEGTUtils::getObjectPosition(object)->copy();
			positionZonly->z = position->z;
			if (delegate->objectsControlsIsObjectCanMoveToPosition(shared_from_this(), object, positionZonly)) {
				FSEGTUtils::getObjectPosition(object)->populate(positionZonly);
			}
		}
	}
}

DMPlayerObjectControls::~DMPlayerObjectControls() {
}

