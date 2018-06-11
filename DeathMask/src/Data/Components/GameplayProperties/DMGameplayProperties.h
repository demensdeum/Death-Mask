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

	DMGameplayProperties();

	void applyDamage(shared_ptr<Damage> damage);
    
	int getAttack();
	int getHealth();
    
 	void setMaxHealth(int maxHealth);
    
	void applyItem(shared_ptr<FSCObject> item);
	void removeItem(shared_ptr<FSCObject> item);
    
	shared_ptr<string> name;    
    
	bool isDead();
    
private:
    
	int health = 0;
	int maxHealth = 0;
	int attack = 0;
	int maxAttack = 0;

	shared_ptr<FSCObject> weapon;
	shared_ptr<FSCObject> bioshell;
	shared_ptr<FSCObject> questItem;

};

#endif /* DMGAMEPLAYPROPERTIES_H */

