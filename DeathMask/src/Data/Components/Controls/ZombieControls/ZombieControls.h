#ifndef DEATHMASKZOMBIECONTROLS_DEFINED
#define DEATHMASKZOMBIECONTROLS_DEFINED 1

#include <DeathMask/src/Data/Components/Controls/DMObjectControls.h>
#include <FlameSteelEngineGameToolkit/Data/FSEGTSimpleDirection.h>
#include <FlameSteelCore/FSCObject.h>
#include <memory>

namespace DeathMaskGame {

class ZombieControls : public DMObjectControls  {

public:
	ZombieControls(shared_ptr<FSCObject> object) : DMObjectControls(object) {}

	virtual void step(shared_ptr<DMObjectControlsDelegate> delegate);

private:
	FSEGTSimpleDirection walkDirection = FSEGTSimpleDirectionDown;
	int walkTime = 0;

};

};

#endif