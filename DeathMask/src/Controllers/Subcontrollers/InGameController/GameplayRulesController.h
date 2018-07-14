#ifndef  GAMEPLAYRULESCONTROLLER_DEFINED
#define GAMEPLAYRULESCONTROLLER_DEFINED 1

#include <memory>
#include <FlameSteelCore/Objects.h>

class GameplayRulesController {

public:	
	GameplayRulesController(shared_ptr<Objects> objects);
	void step();

	bool objectTryingToUseItem(shared_ptr<Object> object, shared_ptr<Object> item);

private:
	shared_ptr<Objects> objects;
	int previousHungerTimer;
	int previousOxygenTimer;

};

#endif