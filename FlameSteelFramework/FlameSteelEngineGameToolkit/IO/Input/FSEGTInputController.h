/*
 * FSEGTInputController.h
 *
 *  Created on: Aug 7, 2016
 *      Author: demensdeum
 */

#ifndef FSEGTINPUTCONTROLLER_H_
#define FSEGTINPUTCONTROLLER_H_

#include <FlameSteelCore/FSCObject.h>
#include <FlameSteelEngineGameToolkit/IO/IOSystems/FSEGTIOSystem.h>

class FSEGTInputController: public FSCObject {
public:
	FSEGTInputController();


	virtual bool isLeftKeyPressed();
	virtual bool isRightKeyPressed();
	virtual bool isUpKeyPressed();
	virtual bool isDownKeyPressed();

	virtual bool isShootKeyPressed();
	virtual bool isExitKeyPressed();

	virtual bool isGenerateMapKeyPressed();

	virtual void pollKey();
	virtual void clearKeys();

	virtual void pollPointerDiff();
        virtual void pollPointerPosition();
        
	virtual int getPointerXdiff();
        virtual int getPointerYdiff();
        
        virtual int getPointerX();
        virtual int getPointerY();

	virtual void clearPointer();

	shared_ptr<FSEGTIOSystem> ioSystem;

	virtual ~FSEGTInputController();

public:
    
	bool leftKeyPressed;
	bool rightKeyPressed;
	bool downKeyPressed;
	bool upKeyPressed;
	bool exitKeyPressed;

	bool shootKeyPressed;

	bool rotateLeftPressed;
	bool rotateRightPressed;

	bool generateMapPressed;
};

#endif /* FSEGTINPUTCONTROLLER_H_ */
