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

	int getHealth();
	int getHealthMax();
	void setHealth(int health);
 	void setHealthMax(int healthMax);

	int getAttack();
	int getAttackMax();
	void setAttack(int attack);
	void setAttackMax(int attackMax);

	int getHunger();
	int getHungerMax();
	void setHunger(int hunger);
	void setHungerMax(int hungerMax);
    
	int getOxygen();
	int getOxygenMax();
	void setOxygen(int oxygen);
	void setOxygenMax(int oxygenMax);

	void applyItem(shared_ptr<FSCObject> item);
	void removeItem(shared_ptr<FSCObject> item);
    
	shared_ptr<string> name;    
    
	bool isDead();
    
private:
    
	int health = 0;
	int healthMax = 0;

	int attack = 0;
	int attackMax = 0;

	int hunger = 0;
	int hungerMax = 0;

	int oxygen = 0;
	int oxygenMax = 0;

	shared_ptr<FSCObject> weapon;
	shared_ptr<FSCObject> bioshell;
	shared_ptr<FSCObject> questItem;

};

#endif /* DMGAMEPLAYPROPERTIES_H */

