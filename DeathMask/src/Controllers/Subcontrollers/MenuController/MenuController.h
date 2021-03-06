#ifndef DEATHMASKMENUCONTROLLER_H_
#define DEATHMASKMENUCONTROLLER_H_

#include <vector>
#include <FlameSteelEngineGameToolkit/Controllers/GameController.h>
#include <FlameSteelEngineGameToolkitAlgorithms/Controllers/CursorController/CursorControllerDelegate.h>
#include <FlameSteelEngineGameToolkit/Controllers/FreeCameraController/FSEGTFreeCameraControllerDelegate.h>

namespace FlameSteelEngine {
namespace GameToolkit {
class FloatComponent;
};
};

using namespace FlameSteelEngine::GameToolkit::Algorithms;

class FSEGTFreeCameraController;

namespace DeathMaskGame {

class MenuController: public GameController, 
								public enable_shared_from_this<MenuController>,
									public FSEGTFreeCameraControllerDelegate,
										public CursorControllerDelegate
{
  
public:
	virtual void beforeStart();
	virtual void step();

	virtual void freeCameraControllerDidUpdateCamera(shared_ptr<FSEGTFreeCameraController> freeCameraController, shared_ptr<Object> camera);
	virtual void cursorControllerDidUpdateCursor(shared_ptr<CursorController> cursorController, shared_ptr<Object> cursor);

private:
    bool cameraUpdated = false;
	shared_ptr<CursorController> cursorController;
	shared_ptr<Object> cursor;
	shared_ptr<Object> camera;
	shared_ptr<Object> gameLogo;
	shared_ptr<FloatComponent> brightness;
	shared_ptr<FloatComponent> logoBrightness;
	shared_ptr<Object> sky;
	shared_ptr<FSEGTFreeCameraController> freeCameraController;
	vector<shared_ptr<Object> > skyscrapers;
	int cooldownTimer = 0;
};

};

#endif
