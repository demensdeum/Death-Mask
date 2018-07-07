#include "GameObjectsGenerator.h"

#include <DeathMask/src/Data/Components/Controls/ZombieControls/ZombieControls.h>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <FlameSteelEngineGameToolkit/Data/Components/Text/FSEGTText.h>
#include <DeathMask/src/Const/DMConstClassIdentifiers.h>
#include <DeathMask/src/Data/Components/Item/ItemProperties.h>
#include <DeathMask/src/Data/GameObjectsGenerator.h>
#include <FlameSteelCore/FSCUtils.h>
#include <DeathMask/src/Data/Components/GameplayProperties/DMGameplayProperties.h>
#include <string>
#include <iostream>

using namespace FlameSteelCore::Utils;
using namespace DeathMaskGame;

GameObjectsGenerator::GameObjectsGenerator() {
}

shared_ptr<FSCObject> GameObjectsGenerator::generateRandomItem(Difficulty itemDifficulty) {

	auto randomItemType = FSCUtils::FSCRandomInt(ItemType::count - 1);

	auto item = shared_ptr<FSCObject>();

	switch (randomItemType)
	{

		case weapon:

			cout << "Generate weapon item" << endl;

			item = generateWeapon(itemDifficulty);
			break;

		case supply:

			cout << "Generate supply item" << endl;

			item  = generateSupplyItem(itemDifficulty);
			break;

		case bioshell:

			cout << "Generate bioshell item" << endl;

			item = generateBioshellItem(itemDifficulty);
			break;

		case questItem:

			cout << "Generate quest item" << endl;

			item = generateQuestItem(itemDifficulty);
			break;

		case oxygenItem:

			cout << "Generate oxygen item" << endl;

			item = generateOxygenItem(itemDifficulty);
			break;

		case foodItem:

			cout << "Generate food item" << endl;

			item = generateFoodItem(itemDifficulty);
			break;

		case count:
			throw logic_error("Can't generate item with incorrect type");

	}

	return item;

}

shared_ptr<FSCObject> GameObjectsGenerator::generateQuestItem(Difficulty difficulty) {

	auto firstNames = vector<string>{LocalizedString("Quest")};
	auto secondNames = vector<string>{LocalizedString("Item")};
	auto type = ItemType::questItem;

	return generateObject(type, difficulty, firstNames, secondNames);

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

      auto object = FSEGTFactory::makeOnSceneObject(
													            make_shared<string>("dummy"),
													            make_shared<string>("dummy"),
													            shared_ptr<string>(),
													            shared_ptr<string>(),
															shared_ptr<string>(),
													            0, 0, 0,
													            1, 1, 1,
													            0, 0, 0,
													            0);   

	object->setClassIdentifier(make_shared<string>(DMConstClassIdentifierEnemy));
	object->setInstanceIdentifier(make_shared<string>(object->uuid));
	
	auto text = make_shared<FSEGTText>(make_shared<string>("Enemy"));
	text->setClassIdentifier(make_shared<string>(DMConstClassIdentifierLabel.c_str()));
	object->addComponent(text);

	auto gameplayProperties = make_shared<DMGameplayProperties>();
	object->addComponent(gameplayProperties);

	auto zombieControls = make_shared<ZombieControls>(object);
	object->addComponent(zombieControls);

	return object;

};

shared_ptr<FSCObject> GameObjectsGenerator::generateOxygenItem(Difficulty oxygenDifficulty) {

	auto firstNames = vector<string>{LocalizedString("Oxygen"), LocalizedString("Oxygen") };
	auto secondNames = vector<string>{LocalizedString("tank"), LocalizedString("cassete"), LocalizedString("tablet")};
	auto type = ItemType::oxygenItem;

	return generateObject(type,  oxygenDifficulty, firstNames, secondNames);

}

shared_ptr<FSCObject> GameObjectsGenerator::generateFoodItem(Difficulty foodDifficulty) {

	auto firstNames = vector<string>{LocalizedString("ForsightTech"), LocalizedString("VitaCom"), LocalizedString("Optimum")};
	auto secondNames = vector<string>{LocalizedString("soyjar"), LocalizedString("grass-bar"), LocalizedString("protein pills")};
	auto type = ItemType::foodItem;

	return generateObject(type, foodDifficulty, firstNames, secondNames);

}

shared_ptr<FSCObject> GameObjectsGenerator::generateWeapon(Difficulty weaponDifficulty) {

	auto firstNames = vector<string>{LocalizedString("Laser"), LocalizedString("Wave"), LocalizedString("Electro-emitted-gravity")};
	auto secondNames = vector<string>{LocalizedString("pistol"), LocalizedString("shotgun"), LocalizedString("machine-gun")};
	auto type = ItemType::weapon;

	return generateObject(type, weaponDifficulty, firstNames, secondNames);

};

shared_ptr<FSCObject> GameObjectsGenerator::generateSupplyItem(Difficulty supplyItemDifficulty) {

	auto firstNames = vector<string>{LocalizedString("VitaCom"), LocalizedString("Human Compatible Nanobots"), LocalizedString("Astra-Life")};
	auto secondNames = vector<string>{LocalizedString("painkiller"), LocalizedString("medkit"), LocalizedString("first aid")};
	auto type = ItemType::supply;

	return generateObject(type, supplyItemDifficulty, firstNames, secondNames);

};

shared_ptr<FSCObject> GameObjectsGenerator::generateBioshellItem(Difficulty bioshellItemDifficulty) {

	auto firstNames = vector<string>{LocalizedString("Advanced"), LocalizedString("Enhanced"), LocalizedString("Cyber")};
	auto secondNames = vector<string>{LocalizedString("legs bioshell"), LocalizedString("hand bioshell"), LocalizedString("eye bioshell")};
	auto type = ItemType::bioshell;

	return generateObject(type, bioshellItemDifficulty, firstNames, secondNames);

}