/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMGameController.h
 * Author: demensdeum
 *
 * Created on April 16, 2017, 5:58 PM
 */

#ifndef DMGAMECONTROLLER_H
#define DMGAMECONTROLLER_H

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTGameController.h>

class DMGameController: public FSEGTGameController {
public:
    DMGameController();
    DMGameController(const DMGameController& orig);
    
    virtual void controllerDidFinish(FSEGTController *controller);  
    
    virtual ~DMGameController();
    
private:

    shared_ptr<FSEGTIOSystem> makeIOSystem();
    
};

#endif /* DMGAMECONTROLLER_H */

