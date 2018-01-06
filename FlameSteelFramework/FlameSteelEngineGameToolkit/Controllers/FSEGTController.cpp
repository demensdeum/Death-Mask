/*
 * FSEGTController.cpp
 *
 *  Created on: Jul 27, 2016
 *      Author: demensdeum
 */

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTController.h>
#include <FlameSteelCore/FSCObject.h>

#include <iostream>

using namespace std;

FSEGTController::FSEGTController() {
	// TODO Auto-generated constructor stub
	gameController = nullptr;
	controllerMessage = shared_ptr<FSCMessage>();
	listener = nullptr;
}

void FSEGTController::beforeStart() {

    if (ioSystem.get() == nullptr) {
        
        cout << "FSEGTController: cannot get ioSystem on controller switching. Is it even initialized? Exit";
        
        exit(1);
        
    }
    
    if (ioSystem->renderer.get() == nullptr) {
        
        cout << "FSEGTController: cannot get ioSystem *Renderer* on controller switching. Is it even initialized? Exit";
        
        exit(1);
        
    }
    
    renderer = ioSystem->renderer;
}

void FSEGTController::step() {

}

void FSEGTController::beforeStop() {

}

void FSEGTController::receivedActionFromSender(int, FSCObject *) {

}

void FSEGTController::controllerDidFinish(FSEGTController *) {
	printf("unhandled empty controller did finish notify\n");
}

void FSEGTController::notifyListenerAboutControllerDidFinish(FSEGTController *) {
	if (listener)
	{
		this->listener->controllerDidFinish(this);
	}
}

void FSEGTController::setGameController(FSEGTGameController* gameController) {
	this->gameController = gameController;
}

void FSEGTController::setControllerMessage(shared_ptr<FSCMessage> controllerMessage) {
	this->controllerMessage = controllerMessage;
}

void FSEGTController::clearMessage() {
	this->controllerMessage = nullptr;
}

shared_ptr<FSCMessage> FSEGTController::getControllerMessage() {
	return this->controllerMessage;
}

FSEGTGameController* FSEGTController::getGameController() {
	return this->gameController;
}

shared_ptr <FSEGTGameData> FSEGTController::getGameData() {
	return this->gameData;
}

void FSEGTController::setGameData(shared_ptr<FSEGTGameData> gameData) {
	this->gameData = gameData;
}

void FSEGTController::handleControllerMessage() {

}

void FSEGTController::clearControllerMessage() {
	this->controllerMessage = shared_ptr<FSCMessage>();
}

void FSEGTController::setIOSystem(shared_ptr<FSEGTIOSystem> ioSystem) {
	this->ioSystem = ioSystem;
	this->renderer = ioSystem->renderer;
}

FSEGTController::~FSEGTController() {
	// TODO Auto-generated destructor stub
}