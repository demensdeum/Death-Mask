#ifndef DEATHMASKMENUCONTROLLER
#define DETAHMASKMENUCONTROLLER

#include <vector>
#include <FlameSteelEngineGameToolkit/Controllers/GameController.h>
#include <FlameSteelEngineGameToolkit/Controllers/FreeCameraController/FSEGTFreeCameraControllerDelegate.h>

namespace FlameSteelEngine {
namespace GameToolkit {
class FloatComponent;
};
};

class FSEGTFreeCameraController;

namespace DeathMaskGame {

class MenuController: public GameController, 
							public enable_shared_from_this<MenuController>,
								public FSEGTFreeCameraControllerDelegate
{
  
public:
	virtual void beforeStart();
	virtual void step();

	virtual void freeCameraControllerDidUpdateCamera(shared_ptr<FSEGTFreeCameraController> freeCameraController, shared_ptr<Object> camera);

private:
	shared_ptr<Object> camera;
	shared_ptr<FloatComponent> brightness;
	shared_ptr<Object> sky;
	shared_ptr<FSEGTFreeCameraController> freeCameraController;
	vector<shared_ptr<Object> > skyscrapers;
};

};

#endif