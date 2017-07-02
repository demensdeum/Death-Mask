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
    
    void rename(shared_ptr<string> name);
    
    void heal(int amount);
    void damage(int amount);
    void healFull();
    
    void addExperience(int amount);
    
    void addItem(shared_ptr<FSCObject> item);
    void removeItem(shared_ptr<FSCObject> item);
    
private:

    shared_ptr<string> name;
    
    string gameplayType;
    
    int health;
    int healthMax;
    
    int experience;
    int experienceMax;
    
    int level;
    
    vector<shared_ptr<FSCObject> > items;
    
    shared_ptr<FSCObject> weapon;
    shared_ptr<FSCObject> gear;
};

#endif /* DMGAMEPLAYPROPERTIES_H */

