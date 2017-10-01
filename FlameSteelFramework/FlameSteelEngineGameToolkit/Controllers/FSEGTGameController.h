/*
 * FSEGTGameController.h
 *
 *  Created on: Jul 27, 2016
 *      Author: demensdeum
 */

#ifndef FSEGTGAMECONTROLLER_H_
#define FSEGTGAMECONTROLLER_H_

#include <memory>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <FlameSteelCore/FSCMessage.h>
#include <FlameSteelCore/FSCResourcesLoader.h>
#include <FlameSteelCore/FSCResourcesManager.h>
#include "FlameSteelEngineGameToolkit/Data/FSEGTGameData.h"
#include <FlameSteelEngineGameToolkit/Controllers/FSEGTController.h>

using namespace std;

class FSEGTGameController : public FSEGTController, public enable_shared_from_this<FSEGTGameController> {
public:
	FSEGTGameController();
	virtual ~FSEGTGameController();

	void setControllerForState(shared_ptr<FSEGTController> controller, int state);

	void setGameControllerMessage(shared_ptr<FSCMessage> message);
	virtual void step();
        
        void gameLoop();
        void startGameFromState(int state);
        
        void setIOSystem(shared_ptr<FSEGTIOSystem> ioSystem);
        
protected:
        shared_ptr<FSCResourcesLoader> resourcesLoader;
        shared_ptr<FSCResourcesManager> resourcesManager;    

        int state;
        
	void switchToState(int state);
	void setIsRunning(bool isRunning);
	virtual void handleGameControllerMessage(shared_ptr<FSCMessage> message);

private:
    
	map<int, shared_ptr<FSEGTController> > stateToControllerMap;
	shared_ptr<FSCMessage> gameControllerMessage;

	shared_ptr<FSEGTController> currentController;
	void setCurrentController(shared_ptr<FSEGTController> newCurrentController);

	void pollGameControllerMessage();
	bool isRunning;
        bool printedSelf;
};

#ifdef __EMSCRIPTEN__

// oh god I don't like javascript for some ugly decisions like those

static FSEGTGameController *GLOBAL_fsegt_emscripten_gameController;
void GLOBAL_fsegt_emscripten_gameLoop();
#endif

#endif /* FSEGTGAMECONTROLLER_H_ */
