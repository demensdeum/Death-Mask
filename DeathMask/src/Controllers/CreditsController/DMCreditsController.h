/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMCreditsController.h
 * Author: demensdeum
 *
 * Created on April 17, 2017, 11:46 PM
 */

#ifndef DMCREDITSCONTROLLER_H
#define DMCREDITSCONTROLLER_H

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTGameController.h>

class DMCreditsController: public FSEGTGameController {
public:
    DMCreditsController();
    DMCreditsController(const DMCreditsController& orig);
    virtual ~DMCreditsController();
    
    virtual void step();
    
private:

};

#endif /* DMCREDITSCONTROLLER_H */

