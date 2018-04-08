#ifndef DMSCENEGENERATORDEFINED
#define DMSCENEGENERATORDEFINED

#include <memory>

using namespace std;

class FSEGTObjectsContext;
class FSEGTGameData;
class FSEGTAMapGeneratorParams;

class FSEGTASceneGenerator {

public:
	void generateScene(shared_ptr<FSEGTObjectsContext> objectsContext, shared_ptr<FSEGTGameData> gameMap,  shared_ptr<FSEGTAMapGeneratorParams> params);

};

#endif