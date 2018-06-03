#include "ObjectsGeneratorTest.h"

#include <iostream>
#include <memory>
#include <DeathMask/src/Const/Const.h>
#include <DeathMask/src/Data/GameObjectsGenerator.h>
#include <DeathMask/src/Utils/DMUtils.h>
#include <FlameSteelEngineGameToolkit/Data/Components/Text/FSEGTText.h>

using namespace std;
using namespace DeathMaskGame;
using namespace DeathMaskGame::Tests;

bool ObjectsGeneratorTest::perform() {

	srand (time(nullptr));

	auto objectsGenerator = make_shared<GameObjectsGenerator>();
	auto supplyItem = objectsGenerator->generateSupplyItem(Difficulty::easy);
	
	if (supplyItem.get() == nullptr) {

		throw logic_error("Test 1 failed");

	}

	cout << "Test 1 passed" << endl;

	auto itemProperties = DMUtils::getObjectItemProperties(supplyItem);

	if (itemProperties->type != ItemType::supply)
	{
		throw logic_error("Test 2 failed");
	}

	cout << "Test 2 passed" << endl;

	auto label = DMUtils::getObjectLabel(supplyItem);

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

	return true;

}