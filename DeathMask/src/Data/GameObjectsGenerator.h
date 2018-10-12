#ifndef DEATHMASKGAMEOBJECTSGENERATOR_DEFINED
#define DEATHMASKGAMEOBJECTSGENERATOR_DEFINED

#include <DeathMask/src/Const/Const.h>

#include <vector>
#include <memory>
#include <FlameSteelCore/Object.h>

#include <FlameSteelEngineGameToolkit/Data/Components/SurfaceMaterial/SurfaceMaterial.h>
#include <DeathMask/src/Data/GameObjectsGenerator.h>

using namespace FlameSteelEngine::GameToolkit;
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

	shared_ptr<Object> makePistol();
	shared_ptr<Object> makeShotgun();
	shared_ptr<Object> makeUzi();
	shared_ptr<Object> makeAssaultRifle();
	shared_ptr<Object> makeGSD(); // Giant Soviet Destructor

private:
	shared_ptr<Object> generateObject(ItemType type, Difficulty itemDiffuclty, vector<string>firstNames, vector<string>secondNames, bool lockedByQuestItem);

	shared_ptr<Object> makeObject(ItemType type, 
									   shared_ptr<string> name, 
									   int minimalEffect,
									   int maximalEffect,
									   bool lockedByQuestItem);

	shared_ptr<SurfaceMaterial> makeSurfaceMaterialWeaponHUD(shared_ptr<string> path, SDL_Rect rect);

};

};

#endif