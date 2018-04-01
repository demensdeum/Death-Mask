#include <memory>

using namespace std;

class FSCObject;
class DMGameMap;

class DMMazeObjectGenerator {

public:
	static shared_ptr<FSCObject> generate(shared_ptr<DMGameMap> gameMap);

private:
	static void putFloorAtXY(shared_ptr<string> serializedMaze, int x, int y, int dotsCount);
	static void putDotAtXY(shared_ptr<string> serializedMaze, int x, int y, int u, int v);

};