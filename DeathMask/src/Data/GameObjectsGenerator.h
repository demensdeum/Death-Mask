#ifndef DEATHMASKGAMEOBJECTSGENERATOR_DEFINED
#define DEATHMASKGAMEOBJECTSGENERATOR_DEFINED

#include <DeathMask/src/Const/Const.h>

#include <vector>
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
	shared_ptr<FSCObject> generateRandomItem(Difficulty itemDifficulty);

private:
	shared_ptr<FSCObject> generateObject(ItemType type, Difficulty itemDiffuclty, vector<string>firstNames, vector<string>secondNames);

};

};

#endif