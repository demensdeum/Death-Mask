#include <math.h>
#include "LookAtRotator.h"
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <FlameSteelEngineGameToolkit/Data/Components/Vector/FSEGTVector.h>

using namespace DeathMaskGame;

LookAtRotator::LookAtRotator(shared_ptr<Object> camera, shared_ptr<Object> target) {

	if (camera.get() == nullptr) {
		throw runtime_error("No camera available");
	}

	if (target.get() == nullptr) {
		throw runtime_error("No target available");
	}

	cameraPosition = FSEGTUtils::getObjectPosition(camera);
	targetPosition = FSEGTUtils:: getObjectPosition(target);

	cameraRotation = FSEGTUtils::getObjectRotation(camera);
	targetRotation = FSEGTUtils::getObjectRotation(target);

}

void LookAtRotator::step() {

		auto diffVector = make_shared<FSEGTVector>();
		diffVector->x = targetPosition->x - cameraPosition->x;
		diffVector->z = targetPosition->z - cameraPosition->z;

		cameraRotation->y = atan2(diffVector->x, diffVector->z);

}