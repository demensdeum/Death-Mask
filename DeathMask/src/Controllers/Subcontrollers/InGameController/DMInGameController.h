#ifndef DMINGAMECONTROLLERDEFINED
#define DMINGAMECONTROLLERDEFINED

class GameplayRulesController;

#include "InGameUserInterfaceController.h"
#include <DeathMask/src/Data/Components/Controls/PlayerControls/DMPlayerObjectControls.h>
#include <FlameSteelCore/FSCMessage.h>
#include <FlameSteelEngineGameToolkit/Controllers/FSEGTController.h>
#include <FlameSteelEngineGameToolkit/Controllers/FreeCameraController/FSEGTFreeCameraControllerDelegate.h>
#include <FlameSteelEngineGameToolkit/Data/ObjectsMap/ObjectsMap.h>

class FSEGTFreeCameraController;

using namespace DeathMaskGame;
using namespace FlameSteelEngine::GameToolkit;

class DMInGameController: public FSEGTController,
									public DMObjectControlsDelegate, 
										public FSEGTFreeCameraControllerDelegate, 
											public enable_shared_from_this<DMInGameController>,
												public InGameUserInterfaceControllerDataSource,
													public FSEGTObjectContextDelegate {

public:
	DMInGameController();

	virtual void beforeStart();    
	virtual void step();

	virtual void freeCameraControllerDidUpdateCamera(shared_ptr<FSEGTFreeCameraController> freeCameraController, shared_ptr<FSCObject> camera);
	virtual void objectsControlsDelegateObjectDidUpdate(shared_ptr<FSCObject> object);
	virtual shared_ptr<FSCObjects> objectsForInGameUserInterfaceController(shared_ptr<InGameUserInterfaceController> inGameUserInterfaceController);

	virtual void objectsContextObjectAdded(shared_ptr<FSEGTObjectsContext> context, shared_ptr<FSCObject> object);
	virtual void objectsContextObjectUpdate(shared_ptr<FSEGTObjectsContext> context, shared_ptr<FSCObject> object);
	virtual void objectsContextAllObjectsRemoved(shared_ptr<FSEGTObjectsContext> context);

private:
	shared_ptr<GameplayRulesController> gameplayRulesController;
	shared_ptr<FSEGTFreeCameraController> freeCameraController;
	shared_ptr<FSCObject> camera;
	shared_ptr<FSCObject> mainCharacter;
	shared_ptr<FSCObject> exitPoint;

	shared_ptr<InGameUserInterfaceController> inGameUserInterfaceController;
	shared_ptr<DMPlayerObjectControls> playerObjectControls;
	shared_ptr<ObjectsMap> objectsMap;

	vector<shared_ptr<FSCMessage> > messages;

	void handleMessages();
	void generateMap();
	void frameStep();

};
#endif