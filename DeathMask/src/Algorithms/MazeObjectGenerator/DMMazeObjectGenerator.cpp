#include <memory>
#include "DMMazeObjectGenerator.h"
#include <FlameSteelFramework/FlameSteelEngineGameToolkit/Data/Components/SerializedModel/FSEGTSerializedModel.h>
#include <DeathMask/src/Data/GameMap/DMGameMap.h>

#include <FlameSteelFramework/FlameSteelCore/FSCObject.h>

#include <iostream>

using namespace std;

shared_ptr<FSCObject> DMMazeObjectGenerator::generate(shared_ptr<DMGameMap> gameMap) {

	auto object = 	make_shared<FSCObject>();

	cout << "Map Object Generator" << endl;

	for (auto y = 0; y < gameMap->height; y++) {
		for (auto x = 0; x < gameMap->width; x++) {

			auto tile = gameMap->getTileIndexAtXY(x ,y);

			cout << tile;
		}
		cout << endl;
	}

	return object;

}