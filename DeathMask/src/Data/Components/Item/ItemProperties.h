#ifndef DEATHMASKGAMEITEMPROPERTIES_DEFINED
#define DEATHMASKGAMEITEMPROPERTIES_DEFINED

#include <FlameSteelCore/FSCObject.h>

namespace DeathMaskGame {

class ItemProperties: public FSCObject {

public:
	ItemProperties(int minimalEffect, int maximalEffect);

	int getMinimalEffect();
	int getMaximalEffect();

	int getRangeRandomEffect();

private:
	int minimalEffect;
	int maximalEffect;

};

}

#endif