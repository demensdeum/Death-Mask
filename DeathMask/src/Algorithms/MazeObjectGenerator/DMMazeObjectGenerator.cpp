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

				if (gameMap->getTileIndexAtXY(x-1,y) == 1) {

					DMMazeObjectGenerator::putLeftWallAtXY(serializedMaze, x, y, dotsCount);

					dotsCount += 4;					

				}

				if (gameMap->getTileIndexAtXY(x+1,y) == 1) {

					DMMazeObjectGenerator::putRightWallAtXY(serializedMaze, x, y, dotsCount);

					dotsCount += 4;					

				}

				if (gameMap->getTileIndexAtXY(x, y - 1) == 1) {

					DMMazeObjectGenerator::putTopWallAtXY(serializedMaze, x, y, dotsCount);

					dotsCount += 4;					

				}

				if (gameMap->getTileIndexAtXY(x, y + 1) == 1) {

					DMMazeObjectGenerator::putDownWallAtXY(serializedMaze, x, y, dotsCount);

					dotsCount += 4;					

				}

			}

			cout << tile;
		}
		cout << endl;
	}

	serializedMaze->append(string("\nMaterial - Texture path = /home/demensdeum/Sources/Death-Mask/DeathMask/data/com.demensdeum.testenvironment.blocktextue.bmp"));

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

	DMMazeObjectGenerator::putDotAtXYZ(serializedMaze, x, 0, y, 0, 1);
	DMMazeObjectGenerator::putDotAtXYZ(serializedMaze, x + 1, 0, y, 1, 1);
	DMMazeObjectGenerator::putDotAtXYZ(serializedMaze, x + 1, 0, y - 1, 1, 0);
	DMMazeObjectGenerator::putDotAtXYZ(serializedMaze, x, 0, y - 1, 0, 0);

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

void DMMazeObjectGenerator::putLeftWallAtXY(shared_ptr<string> serializedMaze, int x, int y, int dotsCount) {

	DMMazeObjectGenerator::putDotAtXYZ(serializedMaze, x, 1, y, 0, 1);
	DMMazeObjectGenerator::putDotAtXYZ(serializedMaze, x, 0, y, 1, 1);
	DMMazeObjectGenerator::putDotAtXYZ(serializedMaze, x, 0, y - 1, 1, 0);
	DMMazeObjectGenerator::putDotAtXYZ(serializedMaze, x, 1, y - 1, 0, 0);

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

void DMMazeObjectGenerator::putRightWallAtXY(shared_ptr<string> serializedMaze, int x, int y, int dotsCount) {

	DMMazeObjectGenerator::putDotAtXYZ(serializedMaze, x + 1, 1, y, 0, 1);
	DMMazeObjectGenerator::putDotAtXYZ(serializedMaze, x + 1, 0, y, 1, 1);
	DMMazeObjectGenerator::putDotAtXYZ(serializedMaze, x + 1, 0, y - 1, 1, 0);
	DMMazeObjectGenerator::putDotAtXYZ(serializedMaze, x + 1, 1, y - 1, 0, 0);

	serializedMaze->append(string("\nIndex = "));
	serializedMaze->append(to_string(dotsCount));
	serializedMaze->append(", ");
	serializedMaze->append(to_string(dotsCount + 2));
	serializedMaze->append(", ");
	serializedMaze->append(to_string(dotsCount + 1));

	serializedMaze->append(string("\nIndex = "));
	serializedMaze->append(to_string(dotsCount + 2));
	serializedMaze->append(", ");
	serializedMaze->append(to_string(dotsCount));
	serializedMaze->append(", ");
	serializedMaze->append(to_string(dotsCount + 3));

}

void DMMazeObjectGenerator::putTopWallAtXY(shared_ptr<string> serializedMaze, int x, int y, int dotsCount) {

	DMMazeObjectGenerator::putDotAtXYZ(serializedMaze, x + 1, 1, y - 1, 0, 1);
	DMMazeObjectGenerator::putDotAtXYZ(serializedMaze, x + 1, 0, y - 1, 1, 1);
	DMMazeObjectGenerator::putDotAtXYZ(serializedMaze, x, 0, y - 1, 1, 0);
	DMMazeObjectGenerator::putDotAtXYZ(serializedMaze, x, 1, y - 1, 0, 0);

	serializedMaze->append(string("\nIndex = "));
	serializedMaze->append(to_string(dotsCount));
	serializedMaze->append(", ");
	serializedMaze->append(to_string(dotsCount + 2));
	serializedMaze->append(", ");
	serializedMaze->append(to_string(dotsCount + 1));

	serializedMaze->append(string("\nIndex = "));
	serializedMaze->append(to_string(dotsCount + 2));
	serializedMaze->append(", ");
	serializedMaze->append(to_string(dotsCount));
	serializedMaze->append(", ");
	serializedMaze->append(to_string(dotsCount + 3));

}

void DMMazeObjectGenerator::putDownWallAtXY(shared_ptr<string> serializedMaze, int x, int y, int dotsCount) {

	DMMazeObjectGenerator::putDotAtXYZ(serializedMaze, x + 1, 1, y, 0, 1);
	DMMazeObjectGenerator::putDotAtXYZ(serializedMaze, x + 1, 0, y, 1, 1);
	DMMazeObjectGenerator::putDotAtXYZ(serializedMaze, x, 0, y, 1, 0);
	DMMazeObjectGenerator::putDotAtXYZ(serializedMaze, x, 1, y, 0, 0);

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

void DMMazeObjectGenerator::putDotAtXYZ(shared_ptr<string> serializedMaze, int x, int y, int z, int u, int v) {

	serializedMaze->append(string("\nVertex - x = "));
	serializedMaze->append(to_string(x));

	serializedMaze->append(string(", y = "));
	serializedMaze->append(to_string(y));

	serializedMaze->append(string(", z = "));
	serializedMaze->append(to_string(z));

	serializedMaze->append(string(", u = "));
	serializedMaze->append(to_string(u));

	serializedMaze->append(string(", v = "));
	serializedMaze->append(to_string(v));

}