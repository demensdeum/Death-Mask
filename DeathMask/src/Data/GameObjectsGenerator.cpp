#include "GameObjectsGenerator.h"

using namespace DeathMaskGame;

GameObjectsGenerator::GameObjectsGenerator() {

	

}

shared_ptr<FSCObject> GameObjectsGenerator::generateEnemy(Difficulty enemyDifficulty) {

	return shared_ptr<FSCObject>();

};

shared_ptr<FSCObject> GameObjectsGenerator::generateWeapon(Difficulty weaponDifficulty) {

	return shared_ptr<FSCObject>();

};

shared_ptr<FSCObject> GameObjectsGenerator::generateSupplyItem(Difficulty supplyItemDifficulty) {

	auto item = make_shared<FSCObject>();
	//item->addComponent();

	return shared_ptr<FSCObject>();

};

shared_ptr<FSCObject> GameObjectsGenerator::generateBioshellItem(Difficulty bioshellItemDifficulty) {

	return shared_ptr<FSCObject>();

}