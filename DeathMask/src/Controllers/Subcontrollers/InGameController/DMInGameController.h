#ifndef DMINGAMECONTROLLERDEFINED
#define DMINGAMECONTROLLERDEFINED

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTController.h>

class DMInGameController: public FSEGTController {

public:
	DMInGameController();

    virtual void beforeStart();    
	virtual void step();

private:
	shared_ptr<FSCObject> dungeon;
};
#endif