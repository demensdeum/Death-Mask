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

#include <DeathMask/src/Const/Const.h>
#include <FlameSteelCore/Object.h>


class Damage;

using namespace DeathMaskGame;
using namespace FlameSteelCore;

class DMGameplayProperties: public Object {
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

	void applyItem(shared_ptr<Object> item);
	void removeItem(shared_ptr<Object> item);
    
	shared_ptr<string> name;    
    
	bool isDead();
    
	CreatureType creatureType = CreatureType::unknown;

private:
    
	int health = 0;
	int healthMax = 0;

	int attack = 0;
	int attackMax = 0;

	int hunger = 0;
	int hungerMax = 0;

	int oxygen = 0;
	int oxygenMax = 0;

	shared_ptr<Object> weapon;
	shared_ptr<Object> bioshell;
	shared_ptr<Object> questItem;
	shared_ptr<Object> supplyItem;

};

#endif /* DMGAMEPLAYPROPERTIES_H */

