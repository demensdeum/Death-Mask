#include "ItemProperties.h"
#include <FlameSteelCore/FSCUtils.h>
#include <DeathMask/src/Const/DMConstClassIdentifiers.h>

using namespace DeathMaskGame;

ItemProperties::ItemProperties(ItemType type, int minimalEffect, int maximalEffect) {

	auto identifier = make_shared<string>(DMConstClassIdentifierItemProperties);

	setClassIdentifier(identifier);
	setInstanceIdentifier(identifier);

	this->type = type;
	this->minimalEffect = minimalEffect;
	this->maximalEffect = maximalEffect;

} 

int ItemProperties::getMinimalEffect() {
	
	return minimalEffect;
}

int ItemProperties::getMaximalEffect() {
	
	return maximalEffect;
}

int ItemProperties::getRangeRandomEffect() {
	
	auto effect = minimalEffect + FSCUtils::FSCRandomInt(maximalEffect - minimalEffect);

	return effect;
}