#include "MapGeneratorTest.h"

#include <memory>
#include <iostream>
#include <FlameSteelCore/FSCUtils.h>
#include <FlameSteelCore/FSCObject.h>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <FlameSteelEngineGameToolkitAlgorithms/Const/Const.h>
#include <FlameSteelEngineGameToolkit/Controllers/FSEGTObjectsContext.h>
#include <FlameSteelEngineGameToolkitAlgorithms/Algorithms/MapGenerator/MapGenerator.h>
#include <FlameSteelEngineGameToolkitAlgorithms/Algorithms/MapGenerator/FSEGTAMapGeneratorParams.h>

using namespace std;
using namespace DeathMaskGame::Tests;
using namespace FlameSteelEngine::GameToolkit::Algorithms;

bool MapGeneratorTest::perform() {

	auto objectsContext = make_shared<FSEGTObjectsContext>();

	shared_ptr<FSCObject> freeTile = std::make_shared<FSCObject>();
	shared_ptr<FSCObject> solidTile = std::make_shared<FSCObject>();
    
	auto mapGeneratorParams = make_shared<FSEGTAMapGeneratorParams>();

	mapGeneratorParams->freeTileIndex = 0;
	mapGeneratorParams->solidTileIndex = 1;

	mapGeneratorParams->tiles.push_back(freeTile);
	mapGeneratorParams->tiles.push_back(solidTile);
    
	mapGeneratorParams->maxIterations = 255;
	mapGeneratorParams->minCursorSize = 2;
	mapGeneratorParams->maxCursorSize = 1 + FSCUtils::FSCRandomInt(6);
	mapGeneratorParams->maxLineLength = 6 + FSCUtils::FSCRandomInt(6);

	auto objects = make_shared<FSCObjects>();

	auto gameMap = MapGenerator::generate(mapGeneratorParams, objectsContext, objects);

	auto startPoint = objectsContext->objectWithInstanceIdentifier(make_shared<string>(ConstMapEntityStartPoint));

	if (startPoint.get() == nullptr)
	{
		throw logic_error("DMInGameController::beforeStart - no start point on map, can't place camera.");
	}

	cout << "Test 1 passed" << endl;

	auto startPointPosition = FSEGTUtils::getObjectPosition(startPoint);

	if (startPointPosition.get() == nullptr)
	{
		throw logic_error("DMInGameController::beforeStart - no start point position, wrong object or incorrect arrangement.");
	}

	cout << "Test 2 passed" << endl;

	auto exitPoint =  objectsContext->objectWithInstanceIdentifier(make_shared<string>(ConstMapEntityEndPoint));

	if (exitPoint.get() == nullptr)
	{
		throw logic_error("DMInGameController::beforeStart - no exit point.");
	}

	cout << "Test 3 passed" << endl;

	auto exitPointPosition = FSEGTUtils::getObjectPosition(exitPoint);

	if (exitPointPosition.get() == nullptr)
	{
		throw logic_error("DMInGameController::beforeStart - no start point position, wrong object or incorrect arrangement.");
	}

	cout << "Test 4 passed" << endl;

	return true;

}