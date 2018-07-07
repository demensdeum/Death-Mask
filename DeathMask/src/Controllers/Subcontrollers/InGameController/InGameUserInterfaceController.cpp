#include "InGameUserInterfaceController.h"

#include <FlameSteelCore/FSCObjects.h>
#include <DeathMask/src/Utils/DMUtils.h>

using namespace DeathMaskGame;

InGameUserInterfaceController::InGameUserInterfaceController(shared_ptr<FSEGTText> text, 
																			shared_ptr<DMGameplayProperties> gameplayProperties,
																				shared_ptr<InGameUserInterfaceControllerDataSource> dataSource) {

	this->text = text;
	this->gameplayProperties = gameplayProperties;
	this->dataSource = dataSource;
}

void InGameUserInterfaceController::step() {

	if (dataSource.get() == nullptr)
	{
		throw logic_error("Data source for in game user interface controller must be provided");
	}

	auto objects = dataSource->objectsForInGameUserInterfaceController(shared_from_this());
	string objectsString = "";
	
	if (objects.get() != nullptr)
	{
		for (int i = 0; i < objects->size(); i++)
		{
			auto object = objects->objectAtIndex(i);
			auto label = DMUtils::getObjectLabel(object);
			objectsString +=  *label->text;
			objectsString += ", ";
		} 

		auto size = objects->size();
		objectsString += std::to_string(size);
	}

	if (objectsString.length() < 1)
	{
		objectsString = "<No objects>";
	}

	char buffer[1024];
	sprintf(buffer, "Name: Revil\nHealth: %d/%d\nAttack: %d/%d\nHunger: %d/%d\nOxygen: %d/%d\nObjects: %s", 
					gameplayProperties->getHealth(), gameplayProperties->getHealthMax(), 
					gameplayProperties->getAttack(), gameplayProperties->getAttackMax(),
					gameplayProperties->getHunger(), gameplayProperties->getHungerMax(),
					gameplayProperties->getOxygen(), gameplayProperties->getOxygenMax(),
					objectsString.c_str());

	text->text = make_shared<string>(buffer);

}

shared_ptr<FSCObjects> InGameUserInterfaceControllerDataSource::objectsForInGameUserInterfaceController(shared_ptr<InGameUserInterfaceController> inGameUserInterfaceController) {

	return shared_ptr<FSCObjects>();

}