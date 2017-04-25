/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMGameController.h
 * Author: demensdeum
 *
 * Created on April 25, 2017, 8:40 AM
 */

#ifndef DMGAMECONTROLLER_H
#define DMGAMECONTROLLER_H

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTSceneController.h>

class DMInGameController: public FSEGTSceneController {
public:
    DMInGameController();
    DMInGameController(const DMInGameController& orig);
    virtual ~DMInGameController();
    
    virtual void beforeStart();    
    virtual void step();
    
private:

};

#endif /* DMGAMECONTROLLER_H */

