#ifndef DEATHMASKGAMETESTSOBJECTSGENERATOR_DEFINED
#define DEATHMASKGAMETESTSOBJECTSGENERATOR_DEFINED

#include <DeathMask/src/Const/Const.h>

namespace DeathMaskGame {
namespace Tests {

class ObjectsGeneratorTest {

public:
	bool perform();

	bool testItemGenerator(ItemType type);

};

}
}

#endif