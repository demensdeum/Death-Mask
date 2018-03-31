#include "FSEGTFreeCameraController.h"

#include <iostream>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include "FSEGTFreeCameraControllerDelegate.h"

FSEGTFreeCameraController::FSEGTFreeCameraController(shared_ptr<FSEGTInputController> inputController, shared_ptr<FSCObject> camera) {

	this->inputController = inputController;
	this->camera = camera;

}

void FSEGTFreeCameraController::step() {

	cout << "step" << endl;

	auto cameraPosition = FSEGTUtils::getObjectPosition(camera);

	auto step = 0.4;
	
	if (inputController->isLeftKeyPressed())
	{
		cameraPosition->x -= step;
	}

	if (inputController->isRightKeyPressed())
	{
		cameraPosition->x += step;
	}

	if (inputController->isUpKeyPressed())
	{
		cameraPosition->z -= step;
	}

	if (inputController->isDownKeyPressed())
	{
		cameraPosition->z += step;
	}

	if (inputController->isShootKeyPressed())
	{
		cameraPosition->y += 0.01;
	}

	auto delegateObject = delegate.lock();

	if (delegateObject.get() != nullptr) {

		delegateObject->freeCameraControllerDidUpdateCamera(shared_from_this(), camera);

	}

}