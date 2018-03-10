/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMUtils.h
 * Author: demensdeum
 *
 * Created on August 19, 2017, 5:08 PM
 */

#ifndef DMUTILS_H
#define DMUTILS_H

#include <DeathMask/src/Data/Components/GameplayProperties/DMGameplayProperties.h>
#include <DeathMask/src/Data/Components/Controls/DMObjectControlsDelegate.h>
#include <DeathMask/src/Data/Components/TileProperties/DMTileProperties.h>
#include <DeathMask/src/Data/Components/Controls/DMObjectControls.h>

#include <FlameSteelCore/FSCObject.h>
#include <memory>

using namespace std;

class DMUtils {
public:
    DMUtils();
    DMUtils(const DMUtils& orig);
    virtual ~DMUtils();
    
    static void incrementHungerForObject(shared_ptr<FSCObject> object);
    
    static shared_ptr<DMGameplayProperties> getGameplayProperties(shared_ptr<FSCObject> object);
    static shared_ptr<DMObjectControls> getObjectControls(shared_ptr<FSCObject> object);
	static shared_ptr<DMTileProperties> getTileProperties(shared_ptr<FSCObject> tile);
    
    static void step(shared_ptr<FSCObject> object, shared_ptr<DMObjectControlsDelegate> delegate);
    
    static void decrementHealthIfNeeded(shared_ptr<FSCObject> object);
    
private:

};

#endif /* DMUTILS_H */

