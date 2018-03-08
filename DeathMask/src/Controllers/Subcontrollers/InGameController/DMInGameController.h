#ifndef DMINGAMECONTROLLERDEFINED
#define DMINGAMECONTROLLERDEFINED

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTController.h>

class DMInGameController: public FSEGTController {

public:
	DMInGameController();

	virtual void step();

};
#endif