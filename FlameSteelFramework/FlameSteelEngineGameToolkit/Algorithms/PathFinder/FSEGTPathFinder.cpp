/*
 * FSEGTPathFinder.cpp
 *
 *  Created on: Sep 16, 2016
 *      Author: demensdeum
 */

#include <FlameSteelEngineGameToolkit/Const/FSEGTConst.h>
#include <FlameSteelEngineGameToolkit/Algorithms/PathFinder/FSEGTPathFinder.h>
#include <FlameSteelEngineGameToolkit/Data/FSEGTGameData.h>
#include <algorithm>
#include <math.h>
#include <cstdlib>

#include <map>

#define FSEGTPATHFINDER_DEBUG 0

FSEGTPathFinder::FSEGTPathFinder() {
	// TODO Auto-generated constructor stub

}

bool FSEGTPathFinder::scoreCompare(FSEGTPathFinderStep& a, FSEGTPathFinderStep& b) {
	return (a.score < b.score);
}

int FSEGTPathFinder::scoreForTile(FSEGTPathFinderStep step, int toTileX, int toTileY) {
	return abs(step.tileX - toTileX) + abs(step.tileY - toTileY);
}

bool FSEGTPathFinder::aStar(shared_ptr<FSEGTGameData> gameData, int tileX, int tileY, int toTileX, int toTileY, vector<FSEGTPathFinderStep> *path, map<FSEGTGameMapTile *, bool> *alreadyViewed) {
    
	auto gameMap = gameData->gameMap;

	if (tileX < 0)
	{
		return false;
	}

	if (tileY < 0)
	{
		return false;
	}

	if (tileX > gameMap->width)
	{
		return false;
	}

	if (tileY > gameMap->height)
	{
		return false;
	}

#if FSEGTPATHFINDER_DEBUG
	printf("aStar step\n");

	printf("tileX: %d\ntileY: %d\ntoTileX: %d\ntoTileY: %d\n",tileX, tileY, toTileX, toTileY);
#endif

	if (tileX == toTileX && tileY == toTileY)
	{
		return true;
	}

	vector<FSEGTPathFinderStep> steps;

	auto gameTile = gameMap->getTileAtXY(tileX - 1, tileY - 1);
	FSEGTPathFinderStep westNorthTile;
	westNorthTile.tileX = tileX - 1;
	westNorthTile.tileY = tileY - 1;
	westNorthTile.score = scoreForTile(westNorthTile, toTileX, toTileY);
	westNorthTile.tile = gameTile.get();

	gameTile = gameMap->getTileAtXY(tileX - 1, tileY);
	FSEGTPathFinderStep westTile;
	westTile.tileX = tileX - 1;
	westTile.tileY = tileY;
	westTile.score = scoreForTile(westTile, toTileX, toTileY);
	westTile.tile = gameTile.get();

	gameTile = gameMap->getTileAtXY(tileX + 1, tileY - 1);
	FSEGTPathFinderStep eastNorthTile;
	eastNorthTile.tileX = tileX + 1;
	eastNorthTile.tileY = tileY - 1;
	eastNorthTile.score = scoreForTile(eastNorthTile, toTileX, toTileY);
	eastNorthTile.tile = gameTile.get();

	gameTile = gameMap->getTileAtXY(tileX + 1, tileY);
	FSEGTPathFinderStep eastTile;
	eastTile.tileX = tileX + 1;
	eastTile.tileY = tileY;
	eastTile.score = scoreForTile(eastTile, toTileX, toTileY);
	eastTile.tile = gameTile.get();

	gameTile = gameMap->getTileAtXY(tileX, tileY - 1);
	FSEGTPathFinderStep northTile;
	northTile.tileX = tileX;
	northTile.tileY = tileY - 1;
	northTile.score = scoreForTile(northTile, toTileX, toTileY);
	northTile.tile = gameTile.get();

	//west south
	gameTile = gameMap->getTileAtXY(tileX - 1, tileY + 1);
	FSEGTPathFinderStep westSouthTile;
	westSouthTile.tileX = tileX - 1;
	westSouthTile.tileY = tileY + 1;
	westSouthTile.score = scoreForTile(westSouthTile, toTileX, toTileY);
	westSouthTile.tile = gameTile.get();

	gameTile = gameMap->getTileAtXY(tileX, tileY + 1);
	FSEGTPathFinderStep southTile;
	southTile.tileX = tileX;
	southTile.tileY = tileY + 1;
	southTile.score = scoreForTile(southTile, toTileX, toTileY);
	southTile.tile = gameTile.get();

	//east south
	gameTile = gameMap->getTileAtXY(tileX + 1, tileY + 1);
	FSEGTPathFinderStep eastSouthTile;
	eastSouthTile.tileX = tileX + 1;
	eastSouthTile.tileY = tileY + 1;
	eastSouthTile.score = scoreForTile(eastSouthTile, toTileX, toTileY);
	eastSouthTile.tile = gameTile.get();

	if (westNorthTile.tile && westNorthTile.tile->isSolid != true)
	{
		steps.push_back(westNorthTile);
	}
	if (westTile.tile && westTile.tile->isSolid != true)
	{
		steps.push_back(westTile);
	}
	if (eastNorthTile.tile && eastNorthTile.tile->isSolid != true)
	{
		steps.push_back(eastNorthTile);
	}

	if (eastSouthTile.tile && eastSouthTile.tile->isSolid != true)
	{
		steps.push_back(eastSouthTile);
	}

	if (eastTile.tile && eastTile.tile->isSolid != true)
	{
		steps.push_back(eastTile);
	}

	if (westSouthTile.tile && westSouthTile.tile->isSolid != true)
	{
		steps.push_back(westSouthTile);
	}

	if (southTile.tile && southTile.tile->isSolid != true)
	{
		steps.push_back(southTile);
	}
	if (northTile.tile && northTile.tile->isSolid != true)
	{
		steps.push_back(northTile);
	}

	sort(steps.begin(), steps.end(), scoreCompare);

	for (int i = 0; i < steps.size(); i++)
	{
		FSEGTPathFinderStep step = steps[i];

		if (step.tile && alreadyViewed->find(step.tile) == alreadyViewed->end())
		{
			alreadyViewed->operator[](step.tile) = true;
			bool tileFound = aStar(gameData, step.tileX, step.tileY, toTileX, toTileY, path, alreadyViewed);

			if (tileFound)
			{
				path->push_back(step);

				return true;
			}
		}
	}

	return false;
}

vector<FSEGTPathFinderStep> FSEGTPathFinder::walkStepsFromXYtoXY(shared_ptr<FSEGTGameData> gameData, float fromX, float fromY, float toX, float toY, int algorithm) {
#if FSEGTPATHFINDER_DEBUG
	printf("walk\nfromX: %f\nfromY: %f\ntoX: %f\ntoY:%f\n", fromX, fromY, toX, toY);
#endif

	int fromTileX = fromX / FSEGTGameMapTileSize;
	int fromTileY = fromY / FSEGTGameMapTileSize;
	int toTileX = toX / FSEGTGameMapTileSize;
	int toTileY = toY / FSEGTGameMapTileSize;

	vector<FSEGTPathFinderStep> path;
	map <FSEGTGameMapTile *, bool> alreadyViewed;

	if (algorithm == FSEGTPathFinderAstar)
	{
		//TODO without recursion
		FSEGTPathFinder::aStar(gameData, fromTileX, fromTileY, toTileX, toTileY, &path, &alreadyViewed);
	}
#if FSEGTPATHFINDER_DEBUG
	printf("path count: %ld", path.size());
#endif

	return path;
}

FSEGTPathFinder::~FSEGTPathFinder() {
	// TODO Auto-generated destructor stub
}

