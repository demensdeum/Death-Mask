 #ifndef DEATHMASKCREDITSCONTROLLER
#define DETAHMASKCREDITSCONTROLLER

#include <FlameSteelEngineGameToolkit/Controllers/GameController.h>
#include <FlameSteelEngineGameToolkit/Controllers/FreeCameraController/FSEGTFreeCameraControllerDelegate.h>

using namespace FlameSteelCore;

namespace FlameSteelEngine {
namespace GameToolkit {
class FloatComponent;
};
};

class FSEGTFreeCameraController;

namespace DeathMaskGame {

class CreditsController: public GameController, 
								public enable_shared_from_this<CreditsController>,
									public FSEGTFreeCameraControllerDelegate
{

public:
	virtual void beforeStart();    
	virtual void step();

	shared_ptr<string> logoPath;

	virtual void freeCameraControllerDidUpdateCamera(shared_ptr<FSEGTFreeCameraController> freeCameraController, shared_ptr<Object> camera);

private:
	shared_ptr<FSEGTFreeCameraController> freeCameraController;
	shared_ptr<Object> camera;
	shared_ptr<Object> companyLogo;
	shared_ptr<FloatComponent> brightness;
	int waitCounter = 0;
};

};

#endif