#ifndef  GAMEPLAYRULESCONTROLLER_DEFINED
#define GAMEPLAYRULESCONTROLLER_DEFINED 1

#include <memory>
#include <FlameSteelCore/Objects.h>

namespace DeathMaskGame {

enum UseItemResultType {

	cant,
	picked,
	questItemNeeded

};

};

using namespace DeathMaskGame;

class GameplayRulesController {

public:	
	GameplayRulesController(shared_ptr<Objects> objects);
	void step();

	UseItemResultType objectTryingToUseItem(shared_ptr<Object> object, shared_ptr<Object> item);

private:
	shared_ptr<Objects> objects;
	int previousSynergyTimer;

};

#endif