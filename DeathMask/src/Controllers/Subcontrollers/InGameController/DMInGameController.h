/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMInGameController.h
 * Author: demensdeum
 *
 * Created on April 26, 2017, 8:42 AM
 */

#ifndef DMINGAMECONTROLLER_H
#define DMINGAMECONTROLLER_H

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTSceneController.h>

class DMInGameController: public FSEGTSceneController {
public:
    DMInGameController();
    DMInGameController(const DMInGameController& orig);
    virtual ~DMInGameController();
    
    virtual void beforeStart();    
    virtual void step();    
    
private:

    shared_ptr<FSEObject> getRevilObject();
    shared_ptr<FSEObject> getExitObject();
    
    shared_ptr<FSEObject> revilObject;
    shared_ptr<FSEObject> exitObject;
    
    void objectPickAtXY(int x, int y);
    
    void pickRandomItem();
    
    void generateMap();
};

#endif /* DMINGAMECONTROLLER_H */

