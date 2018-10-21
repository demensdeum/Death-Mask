/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMObjectControls.h
 * Author: demensdeum
 *
 * Created on August 20, 2017, 12:38 PM
 */

#ifndef DMOBJECTCONTROLS_H
#define DMOBJECTCONTROLS_H

#include <FlameSteelCore/Object.h>
#include "DMObjectControlsDelegate.h"

class DMObjectControls : public Object {
public:
    DMObjectControls(shared_ptr<Object> object);
    DMObjectControls(const DMObjectControls& orig);
    virtual ~DMObjectControls();
    
    virtual void step(shared_ptr<DMObjectControlsDelegate> delegate);
    
protected:
    
    weak_ptr<Object> object;
};

#endif /* DMOBJECTCONTROLS_H */

