/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMGameplayProperties.cpp
 * Author: demensdeum
 * 
 * Created on May 7, 2017, 8:57 PM
 */

#include "DMGameplayProperties.h"

DMGameplayProperties::DMGameplayProperties() {

	setClassIdentifier(make_shared<string>("death mask gameplay properties"));
	setInstanceIdentifier(make_shared<string>(uuid));

}

int DMGameplayProperties::getHealth() {
    
    return health;
}

int DMGameplayProperties::getHealthMax() {

	return healthMax;
}

void DMGameplayProperties::setHealth(int health) {

	this->health = health;
}

void DMGameplayProperties::setHealthMax(int healthMax) {

	this->healthMax = healthMax;
}

int DMGameplayProperties::getAttack() {
    
    return attack;
}

int DMGameplayProperties::getAttackMax() {

	return attackMax;
}

void DMGameplayProperties::setAttack(int attack) {

	this->attack = attack;
}

void DMGameplayProperties::setAttackMax(int attackMax) {

	this->attackMax = attackMax;
}


int DMGameplayProperties::getHunger() {
    
    return hunger;
}

int DMGameplayProperties::getHungerMax() {

	return hungerMax;
}

int DMGameplayProperties::getOxygen() {

	return oxygen;
}

int DMGameplayProperties::getOxygenMax() {

	return oxygenMax;
}

void DMGameplayProperties::setOxygen(int oxygen) {

	this->oxygen = oxygen;
}

void DMGameplayProperties::setOxygenMax(int oxygenMax) {

	this->oxygenMax = oxygenMax;
}


void DMGameplayProperties::setHunger(int hunger) {

	this->hunger = hunger;

}

void DMGameplayProperties::setHungerMax(int hungerMax) {

	this->hungerMax = hungerMax;
}


bool DMGameplayProperties::isDead() {
    
    if (health < 1) {
        
        return true;
        
    }
    
    return false;
}
