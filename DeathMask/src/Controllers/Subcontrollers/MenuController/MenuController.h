#ifndef DEATHMASKMENUCONTROLLER
#define DETAHMASKMENUCONTROLLER

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTController.h>

namespace DeathMaskGame {

class MenuController: public FSEGTController
{

	virtual void beforeStart();    
	virtual void step();

};

};

#endif