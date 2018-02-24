#include <FlameSteelEngineGameToolkit/Controllers/FSEGTController.h>

class DMCorruptedCityController : public FSEGTController {

public:
    virtual void beforeStart();    
    virtual void step();    

private:

	shared_ptr<FSCObject> city;

};