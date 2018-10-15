#include "ZombieControls.h"
#include <math.h>
#include <FlameSteelCore/FSCUtils.h>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <iostream>

using namespace DeathMaskGame;

void ZombieControls::enableLookAt(shared_ptr<Object> target) {

	lookAtRotator = make_shared<LookAtRotator>(object, target);

}

void ZombieControls::step(shared_ptr<DMObjectControlsDelegate> delegate) {

	if (lookAtRotator.get() == nullptr) {
		throw logic_error("Can't rotate zombie, because look at rotator disabled");
	}

	if (object.get() == nullptr)
	{
		throw logic_error("Can't control null zombie");
	}

	auto step = 0.1;

	auto position = FSEGTUtils::getObjectPosition(object)->copy();

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
	}

	lookAtRotator->step();

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
	delegate->objectsControlsDelegateObjectDidUpdate(object);

	walkTime -= 1;

	if (shootTimer >= 120) {

		cout << "zombie controls shoot" << endl;

		shootTimer = 0;

		delegate->objectDidShoot(object);

	}

	shootTimer += 1;
};