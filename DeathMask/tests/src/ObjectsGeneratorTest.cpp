#include "ObjectsGeneratorTest.h"

#include <iostream>
#include <memory>
#include <DeathMask/src/Data/GameObjectsGenerator.h>
#include <DeathMask/src/Utils/DMUtils.h>
#include <FlameSteelEngineGameToolkit/Data/Components/Text/FSEGTText.h>

using namespace std;
using namespace DeathMaskGame;
using namespace DeathMaskGame::Tests;

bool ObjectsGeneratorTest::perform() {

	srand (time(nullptr));

	return testItemGenerator(ItemType::weapon) && 
				testItemGenerator(ItemType::supply) && 
					testItemGenerator(ItemType::bioshell) &&
						testItemGenerator(ItemType::questItem) &&
							testItemGenerator(ItemType::oxygenItem) &&
								testItemGenerator(ItemType::foodItem);
}

bool ObjectsGeneratorTest::testItemGenerator(ItemType type) {

	auto objectsGenerator = make_shared<GameObjectsGenerator>();

	auto item = shared_ptr<Object>();

	switch (type)
	{
		case ItemType::weapon:

			item = objectsGenerator->generateWeapon(Difficulty::easy);
			break;

		case ItemType::supply:

			item = objectsGenerator->generateSupplyItem(Difficulty::easy);
			break;

		case ItemType::bioshell:

			item = objectsGenerator->generateBioshellItem(Difficulty::easy);
			break;

		case ItemType::questItem:

			item = objectsGenerator->generateQuestItem(Difficulty::easy);
			break;

		case ItemType::oxygenItem:

			item = objectsGenerator->generateOxygenItem(Difficulty::easy);
			break;


		case ItemType::foodItem:

			item = objectsGenerator->generateFoodItem(Difficulty::easy);
			break;

	}
	
	if (item.get() == nullptr) {

		throw logic_error("Test 1 failed");

	}

	cout << "Test 1 passed" << endl;

	auto itemProperties = DMUtils::getObjectItemProperties(item);

	if (itemProperties->type != type)
	{
		throw logic_error("Test 2 failed");
	}

	cout << "Test 2 passed" << endl;

	auto label = DMUtils::getObjectLabel(item);

	if (label.get() == nullptr) {

		throw logic_error("Test 3 failed");

	}

	cout << "Test 3 passed" << endl;

	auto text = label->text;

	if (text.get() == nullptr) {

		throw logic_error("Test 4 failed");

	}

	cout << "Test 4 passed" << endl;

	if (text->length() < 1) {

		throw logic_error("Test 5 failed");

	}

	cout << "Test 5 passed" << endl;

	auto minimalEffect = itemProperties->getMinimalEffect();
	auto maximalEffect = itemProperties->getMaximalEffect();
	auto randomRangeEffect = itemProperties->getRangeRandomEffect();

	if (randomRangeEffect < minimalEffect || randomRangeEffect > maximalEffect)
	{
		throw logic_error("Test 6 failed");		
	}

	cout << "Test 6 passed" << endl;

	cout << "Generated object name: " << *text << endl;
	cout << "Generated object minimalEffect " << to_string(itemProperties->getMinimalEffect()) << endl;
	cout << "Generated object maximalEffect " << to_string(itemProperties->getMaximalEffect()) << endl;
	cout << "Generated object rangeEffect " << to_string(itemProperties->getRangeRandomEffect()) << endl;	

	cout << "Test 7 passed" << endl;

	return true;

}