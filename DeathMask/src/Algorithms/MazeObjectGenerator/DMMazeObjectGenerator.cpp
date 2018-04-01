#include <memory>
#include "DMMazeObjectGenerator.h"
#include <FlameSteelCore/FSCObject.h>
#include <DeathMask/src/Data/GameMap/DMGameMap.h>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>

#include <iostream>

using namespace std;

shared_ptr<FSCObject> DMMazeObjectGenerator::generate(shared_ptr<DMGameMap> gameMap) {

	auto serializedMaze = make_shared<string>("Flame Steel Graphics Library Model @ Demens Deum\nModel version = Happy Sasquatch (1.0)\nMesh");

	cout << "Map Object Generator" << endl;

	int dotsCount = 0;

	for (auto y = 0; y < gameMap->height; y++) {
		for (auto x = 0; x < gameMap->width; x++) {

			auto tile = gameMap->getTileIndexAtXY(x ,y);

			if (tile == 0) {

				DMMazeObjectGenerator::putFloorAtXY(serializedMaze, x, y, dotsCount);

				dotsCount += 4;

			}

			cout << tile;
		}
		cout << endl;
	}

	//DMMazeObjectGenerator::putFloorAtXY(serializedMaze, 0, 0, 0);
	//DMMazeObjectGenerator::putFloorAtXY(serializedMaze, 1, 1, 4);

	serializedMaze->append(string("\nMaterial - Texture path = /home/demensdeum/Sources/Death-Mask/DeathMask/data/graphics/models/maps/corruptedCity/blockTexture.bmp"));

auto maze = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("scene object"),
            make_shared<string>("maze"),
            shared_ptr<string>(),
            shared_ptr<string>(),
		serializedMaze,
		0,0,0,
            1, 1, 1,
		0,0,0,
            0);

	return maze;

}

void DMMazeObjectGenerator::putFloorAtXY(shared_ptr<string> serializedMaze, int x, int y, int dotsCount) {

	DMMazeObjectGenerator::putDotAtXY(serializedMaze, x, y, 0, 1);
	DMMazeObjectGenerator::putDotAtXY(serializedMaze, x + 1, y, 1, 1);
	DMMazeObjectGenerator::putDotAtXY(serializedMaze, x + 1, y - 1, 1, 0);
	DMMazeObjectGenerator::putDotAtXY(serializedMaze, x, y - 1, 0, 0);

	serializedMaze->append(string("\nIndex = "));
	serializedMaze->append(to_string(dotsCount));
	serializedMaze->append(", ");
	serializedMaze->append(to_string(dotsCount + 1));
	serializedMaze->append(", ");
	serializedMaze->append(to_string(dotsCount + 2));

	serializedMaze->append(string("\nIndex = "));
	serializedMaze->append(to_string(dotsCount + 3));
	serializedMaze->append(", ");
	serializedMaze->append(to_string(dotsCount));
	serializedMaze->append(", ");
	serializedMaze->append(to_string(dotsCount + 2));

}

void DMMazeObjectGenerator::putDotAtXY(shared_ptr<string> serializedMaze, int x, int y, int u, int v) {

	serializedMaze->append(string("\nVertex - x = "));
	serializedMaze->append(to_string(x));
	serializedMaze->append(string(", y = -0.2, z = "));
	serializedMaze->append(to_string(y));
	serializedMaze->append(string(", u = "));
	serializedMaze->append(to_string(u));
	serializedMaze->append(string(", v = "));
	serializedMaze->append(to_string(v));

}