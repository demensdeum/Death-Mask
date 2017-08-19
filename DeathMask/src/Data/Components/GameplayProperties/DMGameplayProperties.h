/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMGameplayProperties.h
 * Author: demensdeum
 *
 * Created on May 7, 2017, 8:57 PM
 */

#ifndef DMGAMEPLAYPROPERTIES_H
#define DMGAMEPLAYPROPERTIES_H

#include <FlameSteelCore/FSCObject.h>

#include <vector>

class DMGameplayProperties: public FSCObject {
public:
    DMGameplayProperties();
    DMGameplayProperties(const DMGameplayProperties& orig);
    virtual ~DMGameplayProperties();
    
    void heal(int amount);
    void healFull();
    
    void damage(int amount);
    
    int getAttack();
    int getArmor();
    int getHunger();
    
    void useItem(shared_ptr<FSCObject> item);
    
    void incrementHunger();
    
    void addItem(shared_ptr<FSCObject> item);
    void removeItem(shared_ptr<FSCObject> item);
    
    shared_ptr<string> name;    
    
    bool isDead();
    
private:
    
    int health;
    
    int hunger;
    
    vector<shared_ptr<FSCObject> > items;
    
    shared_ptr<FSCObject> weapon;
    shared_ptr<FSCObject> gear;
};

#endif /* DMGAMEPLAYPROPERTIES_H */

