/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMObjectControlsDelegate.h
 * Author: demensdeum
 *
 * Created on August 20, 2017, 12:43 PM
 */

#ifndef DMObjectControlsDelegate_H
#define DMObjectControlsDelegate_H

#include <FlameSteelCore/Object.h>

#include <memory>

using namespace std;
using namespace FlameSteelCore;

class DMObjectControlsDelegate {
public:
    DMObjectControlsDelegate();
    DMObjectControlsDelegate(const DMObjectControlsDelegate& orig);
    virtual ~DMObjectControlsDelegate();
    
    virtual shared_ptr<Object> objectsControlsDelegateObjectAt(int x, int y);
    virtual void objectsControlsDelegateDidPickObject(shared_ptr<Object> object);
    
    virtual void objectsControlsDelegateObjectDidUpdate(shared_ptr<Object> object);
    
private:

};

#endif /* DMObjectControlsDelegate_H */

