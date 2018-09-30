#ifndef DEATHMASKGAMEITEMPROPERTIES_DEFINED
#define DEATHMASKGAMEITEMPROPERTIES_DEFINED

#include <DeathMask/src/Const/Const.h>
#include <FlameSteelCore/Object.h>

using namespace FlameSteelCore;

namespace DeathMaskGame {

class ItemProperties: public Object {

public:
	ItemProperties(ItemType type, int minimalEffect, int maximalEffect, bool lockedByQuestItem);

	ItemType type;

	int getMinimalEffect();
	int getMaximalEffect();

	int getRangeRandomEffect();

	bool lockedByQuestItem = false;

private:
	int minimalEffect;
	int maximalEffect;

};

}

#endif