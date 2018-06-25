#ifndef DMINGAMECONTROLLERDEFINED
#define DMINGAMECONTROLLERDEFINED

#include "InGameUserInterfaceController.h"
#include <DeathMask/src/Data/Components/Controls/PlayerControls/DMPlayerObjectControls.h>
#include <FlameSteelCore/FSCMessage.h>
#include <FlameSteelEngineGameToolkit/Controllers/FSEGTController.h>
#include <FlameSteelEngineGameToolkit/Controllers/FreeCameraController/FSEGTFreeCameraControllerDelegate.h>

class FSEGTFreeCameraController;

using namespace DeathMaskGame;

class DMInGameController: public FSEGTController, public DMObjectControlsDelegate, public FSEGTFreeCameraControllerDelegate, public enable_shared_from_this<DMInGameController> {

public:
	DMInGameController();

    virtual void beforeStart();    
	virtual void step();

	virtual void freeCameraControllerDidUpdateCamera(shared_ptr<FSEGTFreeCameraController> freeCameraController, shared_ptr<FSCObject> camera);
	virtual void objectsControlsDelegateObjectDidUpdate(shared_ptr<FSCObject> object);

private:
	shared_ptr<FSEGTFreeCameraController> freeCameraController;
	shared_ptr<FSCObject> camera;
	shared_ptr<FSCObject> mainCharacter;
	shared_ptr<FSCObject> exitPoint;

	shared_ptr<InGameUserInterfaceController> inGameUserInterfaceController;
	shared_ptr<DMPlayerObjectControls> playerObjectControls;

	vector<shared_ptr<FSCMessage> > messages;

	void handleMessages();
	void generateMap();
	void frameStep();

};
#endif