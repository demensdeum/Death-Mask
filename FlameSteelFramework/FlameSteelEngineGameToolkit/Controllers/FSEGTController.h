/*
 * FSEGTController.h
 *
 *  Created on: Jul 27, 2016
 *      Author: demensdeum
 */

#ifndef FSEGTCONTROLLER_H_
#define FSEGTCONTROLLER_H_

class FSEGTGameController;

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTObjectsContext.h>
#include <FlameSteelEngineGameToolkit/IO/Renderers/FSEGTRenderer.h>
#include <FlameSteelEngineGameToolkit/Data/FSEGTGameData.h>
#include <FlameSteelCore/FSCController.h>
#include <FlameSteelCore/FSCMessage.h>
#include <memory>

using namespace std;

class FSEGTController: public FSCController {
public:
	FSEGTController();
	virtual ~FSEGTController();

	virtual void beforeStart();
	virtual void step();
	virtual void beforeStop();

	void setGameController(FSEGTGameController *gameController);
	FSEGTGameController* getGameController();

	shared_ptr<FSEGTGameData> getGameData();
	virtual void setGameData(shared_ptr<FSEGTGameData> gameData);

	void setControllerMessage(shared_ptr<FSCMessage> controllerMessage);

	void setIOSystem(shared_ptr<FSEGTIOSystem> ioSystem);

	// listener
	FSEGTController *listener;
	virtual void controllerDidFinish(FSEGTController *controller);

	virtual void receivedActionFromSender(int action, FSCObject *sender);

	shared_ptr<FSCMessage> getControllerMessage();
	void clearMessage();
        
protected:

	virtual void notifyListenerAboutControllerDidFinish(FSEGTController *controller);


        
	shared_ptr<FSEGTIOSystem> ioSystem;

	shared_ptr<FSEGTRenderer> renderer;

	shared_ptr<FSEGTGameData> gameData;
	FSEGTGameController* gameController;
	shared_ptr<FSCMessage> controllerMessage;

	virtual void handleControllerMessage();
	virtual void clearControllerMessage();
        
public:
    
        shared_ptr<FSEGTObjectsContext> objectsContext;
        
};

#endif /* FSEGTCONTROLLER_H_ */
