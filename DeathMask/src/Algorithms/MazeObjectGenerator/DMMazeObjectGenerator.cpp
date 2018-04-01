#include <memory>
#include "DMMazeObjectGenerator.h"
#include <FlameSteelCore/FSCObject.h>
#include <DeathMask/src/Data/GameMap/DMGameMap.h>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>

#include <iostream>

using namespace std;

shared_ptr<FSCObject> DMMazeObjectGenerator::generate(shared_ptr<DMGameMap> gameMap) {

	//auto city  = 	make_shared<FSCObject>();

	cout << "Map Object Generator" << endl;

	for (auto y = 0; y < gameMap->height; y++) {
		for (auto x = 0; x < gameMap->width; x++) {

			auto tile = gameMap->getTileIndexAtXY(x ,y);

			cout << tile;
		}
		cout << endl;
	}

auto city = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("scene object"),
            make_shared<string>("revil"),
            shared_ptr<string>(),
            shared_ptr<string>(),
		make_shared<string>("Flame Steel Graphics Library Model @ Demens Deum\nModel version = Happy Sasquatch (1.0)\nMesh\nVertex - x = 0, y = -0.2, z = 0, u = 0, v = 1\nVertex - x = 1, y = -0.2, z = 0, u = 1, v = 1\nVertex - x = 1, y = -0.2, z = -1, u = 1, v = 0\nVertex - x = 0, y = -0.2, z = -1, u = 0, v = 0\nIndex = 0, 1, 2\nIndex = 3, 0, 2\nMaterial - Texture path = /home/demensdeum/Sources/Death-Mask/DeathMask/data/graphics/models/maps/corruptedCity/skytexture.bmp"),
		0,0,0,
            1, 1, 1,
		0,0,0,
            0);

	return city;

}