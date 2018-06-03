#ifndef DEATHMASKGAMEOBJECTSGENERATOR_DEFINED
#define DEATHMASKGAMEOBJECTSGENERATOR_DEFINED

#include <DeathMask/src/Const/Const.h>

#include <memory>
#include <FlameSteelCore/FSCObject.h>

namespace DeathMaskGame {

class GameObjectsGenerator {

public:
	GameObjectsGenerator();

	shared_ptr<FSCObject> generateEnemy(Difficulty enemyDifficulty);
	shared_ptr<FSCObject> generateWeapon(Difficulty weaponDifficulty);
	shared_ptr<FSCObject> generateSupplyItem(Difficulty supplyItemDifficulty);
	shared_ptr<FSCObject> generateBioshellItem(Difficulty bioshellDifficulty);
};

};

#endif