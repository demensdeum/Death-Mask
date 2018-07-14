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
	shared_ptr<Object> generateOxygenItem(Difficulty oxygenDifficulty);
	shared_ptr<Object> generateFoodItem(Difficulty foodDifficulty);
	shared_ptr<Object> generateBioshellItem(Difficulty bioshellDifficulty);
	shared_ptr<Object> generateRandomItem(Difficulty itemDifficulty);
	shared_ptr<Object> generateQuestItem(Difficulty questItemDifficulty);

private:
	shared_ptr<Object> generateObject(ItemType type, Difficulty itemDiffuclty, vector<string>firstNames, vector<string>secondNames);

};

};

#endif