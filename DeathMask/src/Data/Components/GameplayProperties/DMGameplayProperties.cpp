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
#include <DeathMask/src/Utils/DMUtils.h>
#include <FlameSteelEngineGameToolkit/Data/Components/Text/FSEGTText.h>

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

void DMGameplayProperties::addHealth(int effect) {
	health += effect;
	if (health > healthMax) {
		 health = healthMax;
	}
}

shared_ptr<string> DMGameplayProperties::weaponLabel() {
	if (weapon.get() != nullptr) {
		auto label = DMUtils::getObjectLabel(weapon);
		auto text = label->text;
		if (text.get() != nullptr) {
			return label->text;
		}
	}

	return make_shared<string>("<None>");
}

shared_ptr<string> DMGameplayProperties::questItemLabel() {
	if (questItem.get() != nullptr) {
		auto label = DMUtils::getObjectLabel(questItem);
		auto text = label->text;
		if (text.get() != nullptr) {
			return label->text;
		}
	}

	return make_shared<string>("<None>");
}