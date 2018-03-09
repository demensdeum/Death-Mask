#include <memory>
#include "DMMazeObjectGenerator.h"

#include <FlameSteelFramework/FlameSteelCore/FSCObject.h>

using namespace std;

shared_ptr<FSCObject> DMMazeObjectGenerator::generate(shared_ptr<DMGameMap> gameMap) {

	auto object = 	make_shared<FSCObject>();

	return object;

}