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

#include <memory>

using namespace std;

class DMPlayerObjectControls : public DMObjectControls {
public:
    DMPlayerObjectControls(shared_ptr<FSCObject> object, shared_ptr<FSEGTInputController> inputController) : DMObjectControls(object) {
    
        this->inputController = inputController;
    
    };
    virtual ~DMPlayerObjectControls();
    
    shared_ptr<FSEGTInputController> inputController;
    
    virtual void step(shared_ptr<DMObjectControlsDelegate> delegate);
    
private:
    
    void handleTargetAt(int x, int y, shared_ptr<FSEGTVector> position);

};

#endif /* DMPLAYERCONTROLS_H */

