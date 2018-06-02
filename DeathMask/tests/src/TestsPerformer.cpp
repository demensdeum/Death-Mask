#include "TestsPerformer.h"
#include "ObjectsGeneratorTest.h"
#include <memory>
#include <iostream>

using namespace std;
using namespace DeathMaskGame::Tests;

void TestsPerformer::perform() {

	cout << "Tests started" << endl;

	auto objectsGeneratorTest = make_shared<ObjectsGeneratorTest>();
	auto result = objectsGeneratorTest->perform();

	if (!result)
	{
		cout << "Objects Generator Test failed" << endl;
	}

	cout << "Tests ended" << endl;

};