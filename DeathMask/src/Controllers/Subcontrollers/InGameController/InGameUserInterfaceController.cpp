#include "InGameUserInterfaceController.h"

using namespace DeathMaskGame;

InGameUserInterfaceController::InGameUserInterfaceController(shared_ptr<FSEGTText> text, shared_ptr<DMGameplayProperties> gameplayProperties) {

	this->text = text;
	this->gameplayProperties = gameplayProperties;

}

void InGameUserInterfaceController::step() {

	char buffer[1024];
	sprintf(buffer, "Name: Revil\nHealth:%d\nAttack:%d\nHunger:%d", gameplayProperties->getHealth(), gameplayProperties->getAttack(), gameplayProperties->getHunger());

	text->text = make_shared<string>(buffer);

}