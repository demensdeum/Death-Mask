 #ifndef FSGLMODELLOADERFSGLDEFINED
#define FSGLMODELLOADERFSGLDEFINED

#include <string>
#include <memory>

#include <FSGL/Data/ModelLoader/FSGLModelLoader.h>
class FSGLModel;

using namespace std;

class FSGLModelLoaderFSGL: public FSGLModelLoader {

public:
static shared_ptr<FSGLModel> loadModel(shared_ptr<string> modelPath);

};

#endif