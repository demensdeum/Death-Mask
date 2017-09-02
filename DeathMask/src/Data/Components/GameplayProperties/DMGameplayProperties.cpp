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

static const auto DMGamePlayPropertiesMaxHealth = 3;

DMGameplayProperties::DMGameplayProperties() {
    
    name = shared_ptr<string>();
    
    health = 0;
    
    hunger = 0;
}

void DMGameplayProperties::incrementHunger() {
    
    hunger += 1;
    
}

int DMGameplayProperties::getHunger() {
    
    return hunger;
    
}

int DMGameplayProperties::getHealth() {
    
    return health;
}

void DMGameplayProperties::decrementHealth() {
    
    health -= 1;
    
}

void DMGameplayProperties::healFull() {
    
    health = maxHealth;
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

DMGameplayProperties::DMGameplayProperties(const DMGameplayProperties& orig) {
}

DMGameplayProperties::~DMGameplayProperties() {
}

