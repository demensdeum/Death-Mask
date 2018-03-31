#ifndef FSEGTFREECAMERACONTROLLERDEFINED
#define FSEGTFREECAMERACONTROLLERDEFINED

#include <memory>
#include <FlameSteelEngineGameToolkit/IO/Input/FSEGTInputController.h>
#include <FlameSteelCore/FSCObject.h>

class FSEGTFreeCameraControllerDelegate;

using namespace std;

class FSEGTFreeCameraController: public enable_shared_from_this<FSEGTFreeCameraController> {

public:
	FSEGTFreeCameraController(shared_ptr<FSEGTInputController> inputController, shared_ptr<FSCObject> camera);

	void step();

	weak_ptr<FSEGTFreeCameraControllerDelegate> delegate;

private:
	shared_ptr<FSEGTInputController> inputController;
	shared_ptr<FSCObject> camera;
};

#endif