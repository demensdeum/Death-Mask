#include "InGameUserInterfaceController.h"

using namespace DeathMaskGame;

InGameUserInterfaceController::InGameUserInterfaceController(shared_ptr<FSEGTText> text, shared_ptr<DMGameplayProperties> gameplayProperties) {

	this->text = text;
	this->gameplayProperties = gameplayProperties;

}

void InGameUserInterfaceController::step() {

	char buffer[1024];
	sprintf(buffer, "Name: Revil\nHealth:%d/%d\nAttack:%d/%d\nHunger:%d/%d\nOxygen:%d/%d", 
					gameplayProperties->getHealth(), gameplayProperties->getHealthMax(), 
					gameplayProperties->getAttack(), gameplayProperties->getAttackMax(),
					gameplayProperties->getHunger(), gameplayProperties->getHungerMax(),
					gameplayProperties->getOxygen(), gameplayProperties->getOxygenMax());

	text->text = make_shared<string>(buffer);

}