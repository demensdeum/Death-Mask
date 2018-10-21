#ifndef GAMEFINALCONTROLLER_H_
#define GAMEFINALCONTROLLER_H_

#include <FlameSteelFramework/FlameSteelCore/Object.h>
#include <FlameSteelFramework/FlameSteelEngineGameToolkit/Controllers/GameController.h>

namespace DeathMaskGame {

class GameFinalController: public GameController {

public:
	virtual void beforeStart();    
	virtual void step();

private:
	shared_ptr<Object> camera;
	shared_ptr<Object> gameOverImage;

	bool cameraUpdated = false;
	int cooldownTimer = 0;

};

};

#endif