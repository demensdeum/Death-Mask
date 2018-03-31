#ifndef DMINGAMECONTROLLERDEFINED
#define DMINGAMECONTROLLERDEFINED

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTController.h>

#include <FlameSteelEngineGameToolkit/Controllers/FreeCameraController/FSEGTFreeCameraControllerDelegate.h>

class FSEGTFreeCameraController;

class DMInGameController: public FSEGTController, public FSEGTFreeCameraControllerDelegate, public enable_shared_from_this<DMInGameController> {

public:
	DMInGameController();

    virtual void beforeStart();    
	virtual void step();

	virtual void freeCameraControllerDidUpdateCamera(shared_ptr<FSEGTFreeCameraController> freeCameraController, shared_ptr<FSCObject> camera);

private:
	shared_ptr<FSCObject> dungeon;
	shared_ptr<FSEGTFreeCameraController> freeCameraController;
	shared_ptr<FSCObject> camera;
};
#endif