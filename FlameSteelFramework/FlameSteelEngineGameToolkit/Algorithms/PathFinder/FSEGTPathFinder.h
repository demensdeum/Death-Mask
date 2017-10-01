/*
 * FSEGTPathFinder.h
 *
 *  Created on: Sep 16, 2016
 *      Author: demensdeum
 */

#ifndef UTILS_FSEGTPATHFINDER_H_
#define UTILS_FSEGTPATHFINDER_H_

#include <FlameSteelEngineGameToolkit/Data/GameMap/FSEGTGameMapTile.h>

enum {
	FSEGTPathFinderAstar
};

struct FSEGTPathFinderStep {
	int tileX;
	int tileY;
	int score;
	FSEGTGameMapTile *tile;
};

#include <map>
#include <memory>
#include <FlameSteelCore/FSCObject.h>
#include <FlameSteelEngineGameToolkit/Data/FSEGTGameData.h>
#include <FlameSteelEngineGameToolkit/Data/GameMap/FSEGTGameMapTile.h>

using namespace std;

class FSEGTPathFinder: public FSCObject {
public:
	FSEGTPathFinder();

	static vector<FSEGTPathFinderStep> walkStepsFromXYtoXY(shared_ptr<FSEGTGameData> gameData, float fromX, float fromY, float toX, float toY, int algorithm);

	static bool dfs(shared_ptr<FSEGTGameData> gameData, int tileX, int tileY, int toTileX, int toTileY, vector<FSEGTPathFinderStep> *path, map<FSEGTGameMapTile *, bool> *alreadyViewed);
	static bool aStar(shared_ptr<FSEGTGameData> gameData, int tileX, int tileY, int toTileX, int toTileY, vector<FSEGTPathFinderStep> *path, map<FSEGTGameMapTile *, bool> *alreadyViewed);

	virtual ~FSEGTPathFinder();

private:
	static int scoreForTile(FSEGTPathFinderStep step, int toTileX, int toTileY);
	static bool scoreCompare(FSEGTPathFinderStep& a, FSEGTPathFinderStep& b);
	static int calculateH(shared_ptr<FSEGTGameData> gameData, float fromX, float fromY, float toX, float toY);
	static int calculateG(shared_ptr<FSEGTGameData> gameData, float fromX, float fromY, float toX, float toY);
	static int calculateF(shared_ptr<FSEGTGameData> gameData, float fromX, float fromY, float toX, float toY);

};

#endif /* UTILS_FSEGTPATHFINDER_H_ */
