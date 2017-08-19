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

    unique_ptr<DMInGameObjectsController> inGameObjectsController;
    unique_ptr<DMInGameSceneController> inGameSceneController;
};

#endif /* DMINGAMECONTROLLER_H */

