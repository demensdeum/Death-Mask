/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMMenuController.h
 * Author: demensdeum
 *
 * Created on July 1, 2017, 8:18 AM
 */

#ifndef DMMENUCONTROLLER_H
#define DMMENUCONTROLLER_H

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTSceneController.h>

class DMMenuController: public FSEGTSceneController {
public:
    DMMenuController();
    DMMenuController(const DMMenuController& orig);
    virtual ~DMMenuController();
    
    virtual void beforeStart();    
    virtual void step();    
    
private:

        int stepCounter;
};

#endif /* DMMENUCONTROLLER_H */

