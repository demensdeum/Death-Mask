#include <memory>

using namespace std;

class FSCObject;
class DMGameMap;

class DMMazeObjectGenerator {

	static shared_ptr<FSCObject> generate(shared_ptr<DMGameMap> gameMap);

};