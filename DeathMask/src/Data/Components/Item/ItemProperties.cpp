#include "ItemProperties.h"
#include <DeathMask/src/Const/DMConstClassIdentifiers.h>

using namespace DeathMaskGame;

ItemProperties::ItemProperties(int minimalEffect, int maximalEffect) {

	auto identifier = make_shared<string>(DMConstClassIdentifierItemProperties);

	setClassIdentifier(identifier);
	setInstanceIdentifier(identifier);

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
	
	return maximalEffect;
}