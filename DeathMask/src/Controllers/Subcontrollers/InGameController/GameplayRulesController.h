#ifndef  GAMEPLAYRULESCONTROLLER_DEFINED
#define GAMEPLAYRULESCONTROLLER_DEFINED 1

#include <memory>
#include <FlameSteelCore/FSCObjects.h>

class GameplayRulesController {

public:	
	GameplayRulesController(shared_ptr<FSCObjects> objects);
	void step();

private:
	shared_ptr<FSCObjects> objects;
	int previousHungerTimer;
	int previousOxygenTimer;

};

#endif