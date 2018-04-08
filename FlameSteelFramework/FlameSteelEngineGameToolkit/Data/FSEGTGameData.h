/*
 * FSEGTGameData.h
 *
 *  Created on: Jul 31, 2016
 *      Author: demensdeum
 */

#ifndef FSEGTGAMEDATA_H_
#define FSEGTGAMEDATA_H_

#include <map>
#include <FlameSteelCore/FSCObjects.h>
#include <FlameSteelEngineGameToolkit/Data/Components/GameMap/FSEGTGameMap.h>

using namespace std;

class FSEGTGameData: public FSCObject {
public:
	FSEGTGameData();
	virtual ~FSEGTGameData();

public:
	void setGameObjects(shared_ptr<FSCObjects> gameObjects);

	shared_ptr<FSCObjects> getGameObjects();

        shared_ptr<FSEGTGameMap> gameMap;
        
private:
	shared_ptr<FSCObjects> gameObjects; // scene independent game objects
};

#endif /* FSEGTGAMEDATA_H_ */
