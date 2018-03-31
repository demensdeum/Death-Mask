#ifndef FSEGTFREECAMERACONTROLLERDELEGATEDEFINED
#define FSEGTFREECAMERACONTROLLERDELEGATEDEFINED

#include <memory>

using namespace std;

class FSCObject;
class FSEGTFreeCameraController;

class FSEGTFreeCameraControllerDelegate {

public:
	virtual void freeCameraControllerDidUpdateCamera(shared_ptr<FSEGTFreeCameraController> freeCameraController, shared_ptr<FSCObject> camera);

};

#endif