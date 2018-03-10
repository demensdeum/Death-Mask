#include <memory>
#include "DMMazeObjectGenerator.h"

#include <DeathMask/src/IO/IOSystems/FlameSteelEngineGameToolkitFSGL/FSGL/src/Data/Model/FSGLModel.h>
#include <FlameSteelFramework/FlameSteelCore/FSCObject.h>

using namespace std;

shared_ptr<FSCObject> DMMazeObjectGenerator::generate(shared_ptr<DMGameMap> gameMap) {

	auto object = 	make_shared<FSCObject>();

	auto model = make_shared<FSGLModel>();

	auto mesh = make_shared<FSGLMesh>();

	return object;

}