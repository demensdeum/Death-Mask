#include "GameObjectsGenerator.h"

#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <FlameSteelEngineGameToolkit/Data/Components/Text/FSEGTText.h>
#include <DeathMask/src/Const/DMConstClassIdentifiers.h>
#include <DeathMask/src/Data/Components/Item/ItemProperties.h>
#include <DeathMask/src/Data/GameObjectsGenerator.h>
#include <FlameSteelCore/FSCUtils.h>

using namespace DeathMaskGame;

GameObjectsGenerator::GameObjectsGenerator() {
}

shared_ptr<FSCObject> GameObjectsGenerator::generateObject(ItemType type, Difficulty itemDiffuclty, vector<string>firstNames, vector<string>secondNames) {

      auto item = FSEGTFactory::makeOnSceneObject(
													            make_shared<string>("dummy"),
													            make_shared<string>("dummy"),
													            shared_ptr<string>(),
													            shared_ptr<string>(),
															shared_ptr<string>(),
													            0, 0, 0,
													            1, 1, 1,
													            0, 0, 0,
													            0);   

	auto firstRandom = FSCUtils::FSCRandomInt(firstNames.size());
	auto secondRandom = FSCUtils::FSCRandomInt(secondNames.size());

	auto label = firstNames[firstRandom];
	label += " ";
	label += secondNames[secondRandom];

	item->setClassIdentifier(make_shared<string>(DMConstClassIdentifierItem));
	item->setInstanceIdentifier(make_shared<string>(item->uuid));

	auto text = make_shared<FSEGTText>(make_shared<string>(label));
	text->setClassIdentifier(make_shared<string>(DMConstClassIdentifierLabel.c_str()));
	item->addComponent(text);

	auto itemProperties = make_shared<ItemProperties>(type, 5,10);
	item->addComponent(itemProperties);

	return item;
	

};

shared_ptr<FSCObject> GameObjectsGenerator::generateEnemy(Difficulty enemyDifficulty) {

	return shared_ptr<FSCObject>();

};

shared_ptr<FSCObject> GameObjectsGenerator::generateWeapon(Difficulty weaponDifficulty) {

	auto firstNames = vector<string>{"Laser", "Wave", "Electro-emitted-gravity"};
	auto secondNames = vector<string>{"pistol", "shotgun", "machine-gun"};
	auto type = ItemType::weapon;

	return generateObject(type, weaponDifficulty, firstNames, secondNames);

};

shared_ptr<FSCObject> GameObjectsGenerator::generateSupplyItem(Difficulty supplyItemDifficulty) {

	auto firstNames = vector<string>{"VitaCom", "Human Compatible Nanobots", "Astra-Life"};
	auto secondNames = vector<string>{"painkiller", "medkit", "first aid"};
	auto type = ItemType::supply;

	return generateObject(type, supplyItemDifficulty, firstNames, secondNames);

};

shared_ptr<FSCObject> GameObjectsGenerator::generateBioshellItem(Difficulty bioshellItemDifficulty) {

	auto firstNames = vector<string>{"Advanced", "Enhanced", "Cyber"};
	auto secondNames = vector<string>{"legs bioshell", "hand bioshell", "eye bioshell"};
	auto type = ItemType::bioshell;

	return generateObject(type, bioshellItemDifficulty, firstNames, secondNames);

}