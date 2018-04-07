#ifndef DMSCENEGENERATORDEFINED
#define DMSCENEGENERATORDEFINED

#include <memory>

using namespace std;

class FSEGTObjectsContext;
class FSEGTGameData;
class DMMapGeneratorParams;

class DMSceneGenerator {

public:
	void generateScene(shared_ptr<FSEGTObjectsContext> objectsContext, shared_ptr<FSEGTGameData> gameMap,  shared_ptr<DMMapGeneratorParams> params);

};

#endif