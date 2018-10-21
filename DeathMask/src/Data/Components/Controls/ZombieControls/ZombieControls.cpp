#include "ZombieControls.h"
#include <math.h>
#include <FlameSteelCore/FSCUtils.h>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <iostream>

using namespace DeathMaskGame;

void ZombieControls::enableLookAt(shared_ptr<Object> target) {

	auto lockedObject = object.lock();

	if (lockedObject.get() == nullptr) {
		return;
	}

	lookAtRotator = make_shared<LookAtRotator>(lockedObject, target);

}

void ZombieControls::step(shared_ptr<DMObjectControlsDelegate> delegate) {

	if (lookAtRotator.get() == nullptr) {
		throw logic_error("Can't rotate zombie, because look at rotator disabled");
	}

	auto lockedObject = object.lock();

	if (lockedObject.get() == nullptr) {
		return;
	}

	auto step = 0.1;

	auto position = FSEGTUtils::getObjectPosition(lockedObject)->copy();

	if (position.get() == nullptr)
	{
		throw logic_error("Can't control zombie because position is null");
	}

	if (walkTime < 1)
	{
		walkTime = 4 + FSCUtils::FSCRandomInt(40);
		walkDirection = FSEGTSimpleDirection(FSCUtils::FSCRandomInt(FSEGTSimpleDirectionCount));
	}

	switch (walkDirection)
	{
		case FSEGTSimpleDirectionLeft:

			position->x -= step;
			break;

		case FSEGTSimpleDirectionRight:

			position->x += step;
			break;

		case FSEGTSimpleDirectionUp:

		      position->z -= step;
			break;

		case FSEGTSimpleDirectionDown:

		      position->z += step;
			break;
            
        case FSEGTSimpleDirectionCount:
            break;
	}

	lookAtRotator->step();

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
	delegate->objectsControlsDelegateObjectDidUpdate(lockedObject);

	walkTime -= 1;

	if (shootTimer >= 120) {

		cout << "zombie controls shoot" << endl;

		shootTimer = 0;

		delegate->objectDidShoot(lockedObject);

	}

	shootTimer += 1;
};
