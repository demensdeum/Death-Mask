/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InGameObjectsController.h
 * Author: demensdeum
 *
 * Created on August 19, 2017, 11:44 AM
 */

#ifndef INGAMEOBJECTSCONTROLLER_H
#define INGAMEOBJECTSCONTROLLER_H

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTController.h>

class DMInGameObjectsController: public FSEGTController {
public:
    DMInGameObjectsController();
    DMInGameObjectsController(const DMInGameObjectsController& orig);
    virtual ~DMInGameObjectsController();
    
    virtual void step();
    
private:
    
    shared_ptr<FSCObject> getCameraObject();
    shared_ptr<FSCObject> getRevilObject();
    shared_ptr<FSCObject> getExitObject();
    
    void objectPickAtXY(int x, int y);
    
    void pickRandomItem();    

    int roundCounter;
    
    void allObjectsIncrementHunger();
    
};

#endif /* INGAMEOBJECTSCONTROLLER_H */

