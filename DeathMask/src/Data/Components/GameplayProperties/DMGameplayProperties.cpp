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
    
    name = shared_ptr<string>();
    
    gameplayType = string("None");
    
    health = 0;
    healthMax = 0;
    
    experience = 0;
    experienceMax = 0;
}

DMGameplayProperties::DMGameplayProperties(const DMGameplayProperties& orig) {
}

DMGameplayProperties::~DMGameplayProperties() {
}

