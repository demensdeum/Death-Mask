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

class DMGameplayProperties: public Object  {

public:        
	DMGameplayProperties();
    
	shared_ptr<string> name;    
    
	bool isDead();
    
	CreatureType creatureType = CreatureType::unknown;

	int health = 0;
	int healthMax = 0;

	int synergy = 0;
	int synergyMax = 0;

	shared_ptr<Object> weapon;
	shared_ptr<Object> questItem;

public:
	void addSynergy(int effect);
	void addHealth(int effect);

	shared_ptr<string> weaponLabel();
	shared_ptr<string> questItemLabel();

};

#endif /* DMGAMEPLAYPROPERTIES_H */

