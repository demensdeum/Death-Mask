#ifndef DEATHMASKLOOKAT2DROTATOR_H
#define DEATHMASKLOOKAT2DROTATOR_H

#include <memory>
#include <FlameSteelCore/Object.h>

using namespace std;
using namespace FlameSteelCore;

class FSEGTVector;

namespace DeathMaskGame {

class LookAtRotator {

public:
	LookAtRotator(shared_ptr<Object> camera, shared_ptr<Object> target);
	void step();

private:
	shared_ptr<FSEGTVector> cameraPosition;
	shared_ptr<FSEGTVector> targetPosition;

	shared_ptr<FSEGTVector> cameraRotation;
	shared_ptr<FSEGTVector> targetRotation;

};

};

#endif