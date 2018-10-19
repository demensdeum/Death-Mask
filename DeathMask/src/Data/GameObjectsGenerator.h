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

using namespace DeathMaskGame;
using namespace DeathMaskGame::Difficulty;

namespace DeathMaskGame {

class GameObjectsGenerator {

public:
	GameObjectsGenerator();

	static shared_ptr<Object> generateEnemy(enum Difficulty enemyDifficulty);
	static shared_ptr<Object> generateWeapon(enum Difficulty weaponDifficulty);
	static shared_ptr<Object> generateSupplyItem(enum Difficulty supplyItemDifficulty);
	static shared_ptr<Object> generateSynergyItem(enum Difficulty synergyDifficulty);
	static shared_ptr<Object> generateRandomItem(enum Difficulty itemDifficulty);
	static shared_ptr<Object> generateQuestItem(enum Difficulty questItemDifficulty);
	static shared_ptr<Object> generateDeathMask();

	static shared_ptr<Object> makePistol();
	static shared_ptr<Object> makeShotgun();
	static shared_ptr<Object> makeUzi();
	static shared_ptr<Object> makeAssaultRifle();
	static shared_ptr<Object> makeGSD(); // Giant Soviet Destructor

private:
	static shared_ptr<Object> generateObject(ItemType type, enum Difficulty itemDiffuclty, vector<string>firstNames, vector<string>secondNames, bool lockedByQuestItem);

	static shared_ptr<Object> makeObject(ItemType type, 
									   shared_ptr<string> name, 
									   int minimalEffect,
									   int maximalEffect,
									   bool lockedByQuestItem);

	static shared_ptr<SurfaceMaterial> makeSurfaceMaterialWeaponHUD(shared_ptr<string> path, SDL_Rect rect);

};

};

#endif
