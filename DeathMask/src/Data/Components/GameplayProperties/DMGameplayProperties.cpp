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

	setClassIdentifier(make_shared<string>("gameplay properties"));
	setInstanceIdentifier(make_shared<string>(uuid));

}

int DMGameplayProperties::getHealth() {
    
    return health;
}

void DMGameplayProperties::setMaxHealth(int maxHealth) {
    
    this->maxHealth = maxHealth;
}

bool DMGameplayProperties::isDead() {
    
    if (health < 1) {
        
        return true;
        
    }
    
    return false;
}
