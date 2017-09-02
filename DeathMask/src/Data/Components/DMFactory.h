/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMFactory.h
 * Author: demensdeum
 *
 * Created on May 7, 2017, 9:18 PM
 */

#ifndef DMFACTORY_H
#define DMFACTORY_H

#include <FlameSteelCore/FSCObject.h>

class DMFactory {
public:
    DMFactory();
    DMFactory(const DMFactory& orig);
    virtual ~DMFactory();
    
    static shared_ptr<FSCObject> makeRevilObject();
    static shared_ptr<FSCObject> makeAdventurerObject();
    static shared_ptr<FSCObject> makeMaskObject();
    static shared_ptr<FSCObject> makeExitObject();
    static shared_ptr<FSCObject> makeCrate();
    
private:

};

#endif /* DMFACTORY_H */

