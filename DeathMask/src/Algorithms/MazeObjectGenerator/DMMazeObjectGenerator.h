#include <memory>

using namespace std;

class FSCObject;
class DMGameMap;

class DMMazeObjectGenerator {

public:
	static shared_ptr<FSCObject> generate(shared_ptr<DMGameMap> gameMap);

private:
	static void putFloorAtXY(shared_ptr<string> serializedMaze, int x, int y, int dotsCount);
	static void putLeftWallAtXY(shared_ptr<string> serializedMaze, int x, int y, int dotsCount);
	static void putRightWallAtXY(shared_ptr<string> serializedMaze, int x, int y, int dotsCount);
	static void putTopWallAtXY(shared_ptr<string> serializedMaze, int x, int y, int dotsCount);
	static void putDownWallAtXY(shared_ptr<string> serializedMaze, int x, int y, int dotsCount);

	static void putDotAtXYZ(shared_ptr<string> serializedMaze, int x, int y, int z, int u, int v);

};