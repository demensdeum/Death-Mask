/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMInGameSceneController.h
 * Author: demensdeum
 *
 * Created on August 19, 2017, 11:48 AM
 */

#ifndef DMINGAMESCENECONTROLLER_H
#define DMINGAMESCENECONTROLLER_H

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTController.h>

class DMInGameSceneController: public FSEGTController {
public:
    DMInGameSceneController();
    DMInGameSceneController(const DMInGameSceneController& orig);
    virtual ~DMInGameSceneController();
    
    void generateMap();
    
private:

};

#endif /* DMINGAMESCENECONTROLLER_H */

