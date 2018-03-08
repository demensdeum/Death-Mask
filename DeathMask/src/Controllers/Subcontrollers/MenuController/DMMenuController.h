#ifndef DMMENUCONTROLLERDEFINED
#define DMMENUCONTROLLERDEFINED

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTController.h>

class DMMenuController : public FSEGTController {

public:
    virtual void beforeStart();    
    virtual void step();    

private:

	shared_ptr<FSCObject> city;

};

#endif