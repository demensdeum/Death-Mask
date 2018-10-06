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
#include <FlameSteelEngineGameToolkitAlgorithms/Algorithms/MazeObjectGenerator/FSGTAMazeObjectGenerator.h>

using namespace FlameSteelCore::Utils;
using namespace DeathMaskGame;

GameObjectsGenerator::GameObjectsGenerator() {
}

shared_ptr<Object> GameObjectsGenerator::generateRandomItem(Difficulty itemDifficulty) {

	auto randomItemType = FSCUtils::FSCRandomInt(ItemType::count);

	if (randomItemType == deathMask) {
		auto luckyDay = FSCUtils::FSCRandomInt(10) == 3;
		if (luckyDay != true) {
			randomItemType = synergyItem;
		}
	}

	auto item = shared_ptr<Object>();

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

		case questItem:

			cout << "Generate quest item" << endl;

			item = generateQuestItem(itemDifficulty);
			break;

		case synergyItem:

			cout << "Generate synergy item" << endl;

			item = generateSynergyItem(itemDifficulty);
			break;

		case deathMask:

			cout << "Generate death-mask item. yay!" << endl;

			item = generateDeathMask();
			break;

		case count:
			throw logic_error("Can't generate item with incorrect type");

	}

	return item;

}

shared_ptr<Object> GameObjectsGenerator::generateDeathMask() {

	auto firstNames = vector<string>{LocalizedString("Death-Mask")};
	auto secondNames = vector<string>{LocalizedString("")};
	auto type = ItemType::deathMask;

	return generateObject(type, Difficulty::hard, firstNames, secondNames, false);

}

shared_ptr<Object> GameObjectsGenerator::generateQuestItem(Difficulty difficulty) {

	auto firstNames = vector<string>{LocalizedString("Red"), LocalizedString("Yellow"), LocalizedString("Blue")};
	auto secondNames = vector<string>{LocalizedString("Card"), LocalizedString("Key")};
	auto type = ItemType::questItem;

	return generateObject(type, difficulty, firstNames, secondNames, false);

}

shared_ptr<Object> GameObjectsGenerator::generateObject(ItemType type, Difficulty itemDiffuclty, vector<string>firstNames, vector<string>secondNames, bool lockedByQuestItem) {

	auto serializedCardModel = FSGTAMazeObjectGenerator::generateCube(0, 0, make_shared<string>("com.demensdeum.testenvironment.crate.bmp"));

      auto item = FSEGTFactory::makeOnSceneObject(
													            make_shared<string>("dummy"),
													            make_shared<string>("dummy"),
													            shared_ptr<string>(),
													            shared_ptr<string>(),
															serializedCardModel->serializedModelString(),
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

	auto itemProperties = make_shared<ItemProperties>(type, 5,10, lockedByQuestItem);
	item->addComponent(itemProperties);

	return item;
};

shared_ptr<Object> GameObjectsGenerator::generateEnemy(Difficulty enemyDifficulty) {

	auto serializedCubeModel = FSGTAMazeObjectGenerator::generatePlane(1, 1, make_shared<string>("com.demensdeum.testenvironment.enemy.bmp"));

      auto object = FSEGTFactory::makeOnSceneObject(
													            make_shared<string>("dummy"),
													            make_shared<string>("dummy"),
													            shared_ptr<string>(),
													            shared_ptr<string>(),
															serializedCubeModel->serializedModelString(),
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

shared_ptr<Object> GameObjectsGenerator::generateSynergyItem(Difficulty synergyDifficulty) {

	auto firstNames = vector<string>{LocalizedString("Synergy"), LocalizedString("Synergy") };
	auto secondNames = vector<string>{LocalizedString("tank"), LocalizedString("cassete"), LocalizedString("tablet")};
	auto type = ItemType::synergyItem;

	return generateObject(type,  synergyDifficulty, firstNames, secondNames, false);

}

shared_ptr<Object> GameObjectsGenerator::generateWeapon(Difficulty weaponDifficulty) {

	auto firstNames = vector<string>{LocalizedString("Laser"), LocalizedString("Wave"), LocalizedString("Electro-emitted-gravity")};
	auto secondNames = vector<string>{LocalizedString("pistol"), LocalizedString("shotgun"), LocalizedString("machine-gun")};
	auto type = ItemType::weapon;
	auto lockedByQuestItem = FSCUtils::FSCRandomBool();

	return generateObject(type, weaponDifficulty, firstNames, secondNames, lockedByQuestItem);

};

shared_ptr<Object> GameObjectsGenerator::generateSupplyItem(Difficulty supplyItemDifficulty) {

	auto firstNames = vector<string>{LocalizedString("VitaCom"), LocalizedString("Human Compatible Nanobots"), LocalizedString("Astra-Life")};
	auto secondNames = vector<string>{LocalizedString("painkiller"), LocalizedString("medkit"), LocalizedString("first aid")};
	auto type = ItemType::supply;

	return generateObject(type, supplyItemDifficulty, firstNames, secondNames, false);

};
