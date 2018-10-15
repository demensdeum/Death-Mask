#ifndef DMINGAMECONTROLLERDEFINED
#define DMINGAMECONTROLLERDEFINED

class GameplayRulesController;

#include "InGameUserInterfaceController.h"
#include <DeathMask/src/Data/Components/Controls/PlayerControls/DMPlayerObjectControls.h>
#include <FlameSteelCore/Message.h>
#include <FlameSteelEngineGameToolkit/Controllers/GameController.h>
#include <FlameSteelEngineGameToolkit/Controllers/FreeCameraController/FSEGTFreeCameraControllerDelegate.h>
#include <FlameSteelEngineGameToolkit/Data/ObjectsMap/ObjectsMap.h>

class FSEGTFreeCameraController;

using namespace DeathMaskGame;
using namespace FlameSteelEngine::GameToolkit;

class DMInGameController: public GameController,
									public DMObjectControlsDelegate, 
										public FSEGTFreeCameraControllerDelegate, 
											public enable_shared_from_this<DMInGameController>,
												public InGameUserInterfaceControllerDataSource,
													public FSEGTObjectContextDelegate {

public:
	DMInGameController();

	virtual void beforeStart();    
	virtual void step();

	virtual void freeCameraControllerDidUpdateCamera(shared_ptr<FSEGTFreeCameraController> freeCameraController, shared_ptr<Object> camera);
	virtual void objectsControlsDelegateObjectDidUpdate(shared_ptr<Object> object);
	virtual bool objectsControlsIsObjectCanMoveToPosition(shared_ptr<DMObjectControls> objectControls, shared_ptr<Object> object, shared_ptr<FSEGTVector> position);
	virtual shared_ptr<Objects> objectsForInGameUserInterfaceController(shared_ptr<InGameUserInterfaceController> inGameUserInterfaceController);
	virtual shared_ptr<string> messageForInGameUserInterfaceController(shared_ptr<InGameUserInterfaceController> inGameUserInterfaceController);
	virtual void objectDidShoot(shared_ptr<Object> object);

	virtual void objectsContextObjectAdded(shared_ptr<FSEGTObjectsContext> context, shared_ptr<Object> object);
	virtual void objectsContextObjectUpdate(shared_ptr<FSEGTObjectsContext> context, shared_ptr<Object> object);
	virtual void objectsContextAllObjectsRemoved(shared_ptr<FSEGTObjectsContext> context);
	virtual void objectsContextObjectRemoved(shared_ptr<FSEGTObjectsContext> context, shared_ptr<Object> object);

private:
	shared_ptr<GameplayRulesController> gameplayRulesController;
	shared_ptr<FSEGTFreeCameraController> freeCameraController;
	shared_ptr<Object> camera;
	shared_ptr<Object> mainCharacter;
	shared_ptr<Object> exitPoint;
	shared_ptr<Object> uiObject;

	shared_ptr<InGameUserInterfaceController> inGameUserInterfaceController;
	shared_ptr<DMPlayerObjectControls> playerObjectControls;
	shared_ptr<ObjectsMap> objectsMap;
	shared_ptr<Objects> enemies;

	void objectDidHitObject(shared_ptr<Object> object, shared_ptr<Object> hitObject);
	void shooterObjectHitObject(shared_ptr<Object> shooterObject, shared_ptr<Object> hitObject);

	vector<shared_ptr<Message> > messages;

	void useItemAtXY(shared_ptr<Objects> objects);
	void handleMessages();
	void generateMap();
	void frameStep();
	void removeObject(shared_ptr<Object> object);
	void showMessage(shared_ptr<string> message);

	shared_ptr<string> screenMessage;
	int screenMessageTimer = 0;

	bool useItemLocked = false;
	bool shootKeyLocked = false;
};
#endif