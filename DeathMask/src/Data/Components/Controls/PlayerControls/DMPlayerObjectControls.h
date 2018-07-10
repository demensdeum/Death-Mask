/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMPlayerControls.h
 * Author: demensdeum
 *
 * Created on August 20, 2017, 12:55 PM
 */

#ifndef DMPLAYERCONTROLS_H
#define DMPLAYERCONTROLS_H

#include <DeathMask/src/Data/Components/Controls/DMObjectControls.h>

#include <FlameSteelEngineGameToolkit/IO/Input/FSEGTInputController.h>

#include <FlameSteelEngineGameToolkit/Data/Components/Vector/FSEGTVector.h>

#include <FlameSteelFramework/FlameSteelEngineGameToolkit/Data/Components/GameMap/FSEGTGameMap.h>

#include <memory>

using namespace std;

class DMPlayerObjectControls : public DMObjectControls {
public:
    DMPlayerObjectControls(shared_ptr<FSCObject> object, shared_ptr<FSEGTInputController> inputController, shared_ptr<FSEGTGameMap> gameMap) : DMObjectControls(object) {
    
        this->inputController = inputController;
        this->gameMap = gameMap;
        
    };
    virtual ~DMPlayerObjectControls();
    
    shared_ptr<FSEGTInputController> inputController;
    shared_ptr<FSEGTGameMap> gameMap;
    
    virtual void step(shared_ptr<DMObjectControlsDelegate> delegate);

private:
	void moveByRotation(float x, float y, float z);

};

#endif /* DMPLAYERCONTROLS_H */

