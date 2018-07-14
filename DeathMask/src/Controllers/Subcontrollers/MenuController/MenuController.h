#ifndef DEATHMASKMENUCONTROLLER
#define DETAHMASKMENUCONTROLLER

#include <FlameSteelEngineGameToolkit/Controllers/GameController.h>

namespace DeathMaskGame {

class MenuController: public GameController
{

	virtual void beforeStart();    
	virtual void step();

};

};

#endif