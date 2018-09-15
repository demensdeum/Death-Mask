#include "ZombieControls.h"
#include <math.h>
#include <FlameSteelCore/FSCUtils.h>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>

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

	auto position = FSEGTUtils::getObjectPosition(object);

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

	delegate->objectsControlsDelegateObjectDidUpdate(object);

	walkTime -= 1;
};