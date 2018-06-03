#include "TestsPerformer.h"
#include "ObjectsGeneratorTest.h"
#include "MapGeneratorTest.h"
#include <memory>
#include <iostream>

using namespace std;
using namespace DeathMaskGame::Tests;

void TestsPerformer::perform() {

	cout << "Tests started" << endl;

	{
		auto objectsGeneratorTest = make_shared<ObjectsGeneratorTest>();
		auto result = objectsGeneratorTest->perform();

		if (!result)
		{
			throw logic_error("Objects Generator Test failed");
		}
	}

	{
		auto mapGeneratorTest = make_shared<MapGeneratorTest>();
		auto result = mapGeneratorTest->perform();

		if (!result)
		{
			throw logic_error("Map Generator Test failed");
		}
	}

	cout << "Tests ended" << endl;

};