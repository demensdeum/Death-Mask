//
//  GameplayRulesControllerDelegate.h
//  DeathMask
//
//  Created by Ilia Prokhorov on 20/10/2018.
//

#ifndef DeathMaskGameplayRulesControllerDelegate_h
#define DeathMaskGameplayRulesControllerDelegate_h

namespace FlameSteelCore {
    class Object;
}

namespace DeathMaskGame {
    class GameplayRulesController;
}

namespace DeathMaskGame {
    
    class GameplayRulesControllerDelegate {
        
    public:
	virtual void gameplayRulesControllerMainCharacterDidDie(shared_ptr<GameplayRulesController> gameplayRulesController,
                                                         shared_ptr<Object> mainCharacter) = 0;

	virtual void gameplayRulesControllerMainCharacterDidFoundDeathMask(shared_ptr<GameplayRulesController> gameplayRulesController) = 0;
        
    };
    
}

#endif /* GameplayRulesControllerDelegate_h */
