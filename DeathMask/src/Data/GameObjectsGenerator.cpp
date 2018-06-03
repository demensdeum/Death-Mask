#include "GameObjectsGenerator.h"

#include <FlameSteelEngineGameToolkit/Data/Components/Text/FSEGTText.h>
#include <DeathMask/src/Const/DMConstClassIdentifiers.h>
#include <DeathMask/src/Data/Components/Item/ItemProperties.h>
#include <DeathMask/src/Data/GameObjectsGenerator.h>
#include <FlameSteelCore/FSCUtils.h>
#include <vector>

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

	auto firstNames = vector<string>{"VitaCom", "Heal", "Astra-Life"};
	auto secondNames = vector<string>{"painkiller", "medkit", "first aid"};

	auto firstRandom = FSCUtils::FSCRandomInt(firstNames.size());
	auto secondRandom = FSCUtils::FSCRandomInt(secondNames.size());

	auto label = firstNames[firstRandom];
	label += " ";
	label += secondNames[secondRandom];

	auto item = make_shared<FSCObject>();
	item->setClassIdentifier(make_shared<string>(DMConstClassIdentifierItem));
	item->setInstanceIdentifier(make_shared<string>(item->uuid));

	auto text = make_shared<FSEGTText>(make_shared<string>(label));
	text->setClassIdentifier(make_shared<string>(DMConstClassIdentifierLabel.c_str()));
	item->addComponent(text);

	auto itemProperties = make_shared<ItemProperties>(ItemType::supply, 5,10);
	item->addComponent(itemProperties);

	return item;

};

shared_ptr<FSCObject> GameObjectsGenerator::generateBioshellItem(Difficulty bioshellItemDifficulty) {

	return shared_ptr<FSCObject>();

}