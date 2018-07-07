#include "ZombieControls.h"
#include <FlameSteelCore/FSCUtils.h>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>

using namespace DeathMaskGame;

void ZombieControls::step(shared_ptr<DMObjectControlsDelegate> delegate) {

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

	delegate->objectsControlsDelegateObjectDidUpdate(object);

	walkTime -= 1;
};