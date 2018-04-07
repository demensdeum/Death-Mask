/*
 * FSEGTInputController.cpp
 *
 *  Created on: Aug 7, 2016
 *      Author: demensdeum
 */

#include "FSEGTInputController.h"

FSEGTInputController::FSEGTInputController() {
	this->ioSystem = nullptr;
	this->leftKeyPressed = false;
	this->rightKeyPressed = false;
	this->downKeyPressed = false;
	this->upKeyPressed = false;
	this->generateMapPressed = false;

	this->rotateLeftKeyPressed = false;
	this->rotateRightKeyPressed = false;

	this->exitKeyPressed = false;
	this->shootKeyPressed = false;

}

bool FSEGTInputController::isRotateLeftKeyPressed() {

	return this->rotateLeftKeyPressed;

}

bool FSEGTInputController::isRotateRightKeyPressed() {

	return this->rotateRightKeyPressed;

}

void FSEGTInputController::pollKey() {

}

void FSEGTInputController::clearKeys() {
	this->leftKeyPressed = false;
	this->rightKeyPressed = false;
	this->downKeyPressed = false;
	this->upKeyPressed = false;
	this->generateMapPressed = false;

	this->rotateLeftKeyPressed = false;
	this->rotateRightKeyPressed = false;

	this->exitKeyPressed = false;
	this->shootKeyPressed = false;
}

bool FSEGTInputController::isGenerateMapKeyPressed() {
	return this->generateMapPressed;
}

bool FSEGTInputController::isExitKeyPressed() {
	return this->exitKeyPressed;
}

bool FSEGTInputController::isLeftKeyPressed() {
	return this->leftKeyPressed;
}

bool FSEGTInputController::isRightKeyPressed() {
	return this->rightKeyPressed;
}

bool FSEGTInputController::isUpKeyPressed() {
	return this->upKeyPressed;
}

bool FSEGTInputController::isDownKeyPressed() {
	return this->downKeyPressed;
}

bool FSEGTInputController::isShootKeyPressed() {
	return this->shootKeyPressed;
}

void FSEGTInputController::pollPointerPosition() {

}

void FSEGTInputController::pollPointerDiff() {

}

int FSEGTInputController::getPointerXdiff() {

	return 0;
}

int FSEGTInputController::getPointerYdiff() {

	return 0;
}

int FSEGTInputController::getPointerX() {

	return 0;
}

int FSEGTInputController::getPointerY() {

	return 0;
}

void FSEGTInputController::clearPointer() {

}

FSEGTInputController::~FSEGTInputController() {
	// TODO Auto-generated destructor stub
}
