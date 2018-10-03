#ifndef DEATHMASKGAMEOBJECTSGENERATOR_DEFINED
#define DEATHMASKGAMEOBJECTSGENERATOR_DEFINED

#include <DeathMask/src/Const/Const.h>

#include <vector>
#include <memory>
#include <FlameSteelCore/Object.h>

using namespace FlameSteelCore;

namespace DeathMaskGame {

class GameObjectsGenerator {

public:
	GameObjectsGenerator();

	shared_ptr<Object> generateEnemy(Difficulty enemyDifficulty);
	shared_ptr<Object> generateWeapon(Difficulty weaponDifficulty);
	shared_ptr<Object> generateSupplyItem(Difficulty supplyItemDifficulty);
	shared_ptr<Object> generateSynergyItem(Difficulty synergyDifficulty);
	shared_ptr<Object> generateRandomItem(Difficulty itemDifficulty);
	shared_ptr<Object> generateQuestItem(Difficulty questItemDifficulty);
	shared_ptr<Object> generateDeathMask();

private:
	shared_ptr<Object> generateObject(ItemType type, Difficulty itemDiffuclty, vector<string>firstNames, vector<string>secondNames, bool lockedByQuestItem);

};

};

#endif