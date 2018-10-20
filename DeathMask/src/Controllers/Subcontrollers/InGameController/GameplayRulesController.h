#ifndef  GAMEPLAYRULESCONTROLLER_DEFINED
#define GAMEPLAYRULESCONTROLLER_DEFINED 1

#include <memory>
#include <FlameSteelCore/Object.h>
#include <FlameSteelCore/Objects.h>
#include "GameplayRulesControllerDelegate.h"

namespace DeathMaskGame {

enum UseItemResultType {

	cant,
	picked,
	questItemNeeded

};

};

using namespace DeathMaskGame;

namespace DeathMaskGame {

class GameplayRulesController: public enable_shared_from_this<GameplayRulesController> {

public:	
	GameplayRulesController(shared_ptr<Objects> objects,
                            shared_ptr<Object> mainCharacter,
                            shared_ptr<GameplayRulesControllerDelegate> delegate);
	void step();

	UseItemResultType objectTryingToUseItem(shared_ptr<Object> object, shared_ptr<Object> item);

private:
    shared_ptr<GameplayRulesControllerDelegate> delegate;
    shared_ptr<Object> mainCharacter;
	shared_ptr<Objects> objects;
	int previousSynergyTimer;

};
};

#endif
