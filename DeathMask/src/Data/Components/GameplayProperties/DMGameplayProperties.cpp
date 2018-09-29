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

bool DMGameplayProperties::isDead() {
        return health < 1;
}

void DMGameplayProperties::addSynergy(int effect) {
	synergy += effect;
	if (synergy > synergyMax) {
		synergy = synergyMax;
	}
}