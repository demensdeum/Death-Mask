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

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTController.h>

#include <DeathMask/src/Controllers/Subcontrollers/InGameController/Subcontrollers/InGameUIController/DMInGameUIController.h>
#include <DeathMask/src/Controllers/Subcontrollers/InGameController/Subcontrollers/InGameSceneController/DMInGameSceneController.h>
#include <DeathMask/src/Controllers/Subcontrollers/InGameController/Subcontrollers/InGameObjectsController/DMInGameObjectsController.h>

class DMInGameController: public FSEGTController {
public:
    DMInGameController();
    DMInGameController(const DMInGameController& orig);
    virtual ~DMInGameController();
    
    virtual void beforeStart();    
    virtual void step();    
    
private:

    void initializeSubcontroller(shared_ptr<FSEGTController> subcontroller);
    
    shared_ptr<DMInGameObjectsController> inGameObjectsController;
    shared_ptr<DMInGameSceneController> inGameSceneController;
    shared_ptr<DMInGameUIController> inGameUIController;
};

#endif /* DMINGAMECONTROLLER_H */

