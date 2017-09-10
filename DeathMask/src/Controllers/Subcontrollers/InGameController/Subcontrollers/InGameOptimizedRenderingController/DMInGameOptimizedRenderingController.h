/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMInGameOptimizedRenderingController.h
 * Author: demensdeum
 *
 * Created on September 10, 2017, 1:25 PM
 */

#ifndef DMINGAMEOPTIMIZEDRENDERINGCONTROLLER_H
#define DMINGAMEOPTIMIZEDRENDERINGCONTROLLER_H

#include <set>

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTController.h>

class DMInGameOptimizedRenderingController: public FSEGTController {
    
public:
    DMInGameOptimizedRenderingController();
    DMInGameOptimizedRenderingController(const DMInGameOptimizedRenderingController& orig);
    virtual ~DMInGameOptimizedRenderingController();
    
    set<int> renderingIDs();
    
private:

    shared_ptr<FSCObject> getRevilObject();
};

#endif /* DMINGAMEOPTIMIZEDRENDERINGCONTROLLER_H */

