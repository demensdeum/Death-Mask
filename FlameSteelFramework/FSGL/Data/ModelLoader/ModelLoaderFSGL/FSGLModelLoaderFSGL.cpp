#include "FSGLModelLoaderFSGL.h"

#include <fstream>
#include <sstream>

 shared_ptr<FSGLModel> FSGLModelLoaderFSGL::loadModel(shared_ptr<string> modelPath) {

	std::ifstream t(modelPath->c_str());
	std::stringstream buffer;
	buffer << t.rdbuf();

	auto serializedModelString = make_shared<string>(buffer.str());

	auto model = make_shared<FSGLModel>()->deserializeFromString(serializedModelString);

	return static_pointer_cast<FSGLModel>(model);

}