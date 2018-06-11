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

class Damage;

class DMGameplayProperties: public FSCObject {
public:        
	void applyDamage(shared_ptr<Damage> damage);
    
	int getAttack();
	int getHealth();
    
 	void setMaxHealth(int maxHealth);
    
	void applyItem(shared_ptr<FSCObject> item);
	void removeItem(shared_ptr<FSCObject> item);
    
	shared_ptr<string> name;    
    
	bool isDead();
    
private:
    
	int health;
	int maxHealth;
     
	shared_ptr<FSCObject> weapon;
	shared_ptr<FSCObject> bioshell;
	shared_ptr<FSCObject> questItem;

};

#endif /* DMGAMEPLAYPROPERTIES_H */

