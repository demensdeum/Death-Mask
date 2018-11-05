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
#include <iostream>

using namespace std;

#include <glm/gtc/matrix_transform.hpp>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>

#define DMPLAYEROBJECTCONTROLSMOVEBYDIRECTION 1

void DMPlayerObjectControls::step(shared_ptr<DMObjectControlsDelegate> delegate) {

	bool updateNeeded = false;

	auto step = 0.1;

	auto lockedObject = object.lock();

	if (lockedObject.get() == nullptr) {
		return;
	}

	auto rotation = FSEGTUtils::getObjectRotation(lockedObject);
	auto position = FSEGTUtils::getObjectPosition(lockedObject);
      
	bool leftKeyPressed = inputController->isLeftKeyPressed();
	bool rightKeyPressed = inputController->isRightKeyPressed();
	bool downKeyPressed = inputController->isDownKeyPressed();
	bool upKeyPressed = inputController->isUpKeyPressed();

	int stickOffset = 6;

	auto moveStick = stickController->moveStick;

	if (moveStick.get() != nullptr) {

		if (moveStick->x < -stickOffset) {
			leftKeyPressed = true;
		}

		if (moveStick->x > stickOffset) {
			rightKeyPressed = true;
		}

		if (moveStick->y < -stickOffset) {
			upKeyPressed = true;
		}

		if (moveStick->y > stickOffset) {
			downKeyPressed = true;
		}

	}

	auto viewStick = stickController->viewStick;

	if (viewStick.get() != nullptr) {

		if (viewTouchStartX == -1) {
			viewTouchStartX = rotation->y;
		}
		else {
			rotation->y = viewTouchStartX - float(viewStick->x) / 200;
		}

	}
	else {

		viewTouchStartX = -1;

	}

	if (leftKeyPressed) {

#if DMPLAYEROBJECTCONTROLSMOVEBYDIRECTION == 1
		moveByRotation(-step, 0, 0, delegate);
#else
		position->x -= step;
#endif
		updateNeeded = true;        

	}

	if (rightKeyPressed) {

#if DMPLAYEROBJECTCONTROLSMOVEBYDIRECTION == 1
		moveByRotation(step, 0, 0, delegate);
#else
		position->x += step;
#endif
		updateNeeded = true;        

	}
  
	if (downKeyPressed) {    

#if DMPLAYEROBJECTCONTROLSMOVEBYDIRECTION == 1
		moveByRotation(0, 0, step, delegate);
#else
		position->z += step;
#endif
		updateNeeded = true;

	}

	if (upKeyPressed) {

#if DMPLAYEROBJECTCONTROLSMOVEBYDIRECTION == 1
		moveByRotation(0, 0, -step, delegate);
#else
		position->z -= step;
#endif
		updateNeeded = true;

	}

	if (inputController->pointerXdiff != 0)
	{
		rotation->y -= float(inputController->pointerXdiff) / 200;
	}

	if (updateNeeded)
	{
		delegate->objectsControlsDelegateObjectDidUpdate(lockedObject);
	}
}

void DMPlayerObjectControls::moveByRotation(float x, float y, float z, shared_ptr<DMObjectControlsDelegate> delegate) {

		auto lockedObject = object.lock();

		if (lockedObject.get() == nullptr) {
			return;
		}

		auto position = FSEGTUtils::getObjectPosition(lockedObject)->copy();
		auto rotation = FSEGTUtils::getObjectRotation(lockedObject);

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

	if (delegate->objectsControlsIsObjectCanMoveToPosition(shared_from_this(), lockedObject, position)) {
		FSEGTUtils::getObjectPosition(lockedObject)->populate(position);
	}
	else {
		// only x
		auto positionXonly = FSEGTUtils::getObjectPosition(lockedObject)->copy();
		positionXonly->x = position->x;
		if (delegate->objectsControlsIsObjectCanMoveToPosition(shared_from_this(), lockedObject, positionXonly)) {
			FSEGTUtils::getObjectPosition(lockedObject)->populate(positionXonly);
		}
		else {
			// only z
			auto positionZonly = FSEGTUtils::getObjectPosition(lockedObject)->copy();
			positionZonly->z = position->z;
			if (delegate->objectsControlsIsObjectCanMoveToPosition(shared_from_this(), lockedObject, positionZonly)) {
				FSEGTUtils::getObjectPosition(lockedObject)->populate(positionZonly);
			}
		}
	}
}

DMPlayerObjectControls::~DMPlayerObjectControls() {
}

