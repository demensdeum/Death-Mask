#ifndef DEATHMASKZOMBIECONTROLS_DEFINED
#define DEATHMASKZOMBIECONTROLS_DEFINED 1

#include <DeathMask/src/Data/Components/Controls/LookAtRotator/LookAtRotator.h>
#include <DeathMask/src/Data/Components/Controls/DMObjectControls.h>
#include <FlameSteelEngineGameToolkit/Data/FSEGTSimpleDirection.h>
#include <FlameSteelCore/Object.h>
#include <memory>

namespace DeathMaskGame {

class ZombieControls : public DMObjectControls, public enable_shared_from_this<ZombieControls> {

public:
	ZombieControls(shared_ptr<Object> object) : DMObjectControls(object) {
		setInstanceIdentifier(make_shared<string>("zombie controls"));
	}

	virtual void step(shared_ptr<DMObjectControlsDelegate> delegate);
	void enableLookAt(shared_ptr<Object> target);

private:
	FSEGTSimpleDirection walkDirection = FSEGTSimpleDirectionDown;
	int walkTime = 0;

	shared_ptr<LookAtRotator> lookAtRotator;

	int shootTimer = 0;

};

};

#endif