#ifndef DEATHMASKGAMEITEMPROPERTIES_DEFINED
#define DEATHMASKGAMEITEMPROPERTIES_DEFINED

#include <DeathMask/src/Const/Const.h>
#include <FlameSteelCore/Object.h>

using namespace FlameSteelCore;

namespace DeathMaskGame {

class ItemProperties: public Object {

public:
	ItemProperties(ItemType type, int minimalEffect, int maximalEffect);

	ItemType type;

	int getMinimalEffect();
	int getMaximalEffect();

	int getRangeRandomEffect();

private:
	int minimalEffect;
	int maximalEffect;

};

}

#endif