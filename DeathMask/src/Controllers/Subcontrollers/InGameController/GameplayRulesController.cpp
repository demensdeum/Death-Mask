#include <ctime>
#include "GameplayRulesController.h"
#include <DeathMask/src/Utils/DMUtils.h>
#include <iostream>
#include <DeathMask/src/Const/DMConstClassIdentifiers.h>

using namespace DeathMaskGame;

GameplayRulesController::GameplayRulesController(shared_ptr<Objects> objects) 
{
	if (objects.get() == nullptr)
	{
		throw logic_error("Can't initialize Gameplay Rules Controller with null objects pointer");
	}

	previousSynergyTimer = 0;

	this->objects = objects;
}

void GameplayRulesController::step()
{
	auto synergyTimer = std::time(nullptr);
	auto shouldDecrementSynergy = synergyTimer  > 20 + previousSynergyTimer;

	for (auto i = 0; i < objects->size(); i++)
	{
		auto object = objects->objectAtIndex(i);
		auto gameplayProperties = DMUtils::getObjectGameplayProperties(object);

		if (gameplayProperties->creatureType == CreatureType::living && shouldDecrementSynergy)
		{
			gameplayProperties->synergy -= 1;
		}
	}

	if (shouldDecrementSynergy)
	{
		previousSynergyTimer = synergyTimer;		
	}
}

bool GameplayRulesController::objectTryingToUseItem(shared_ptr<Object> object, shared_ptr<Object> item)
{
	auto gameplayProperties = DMUtils::getObjectGameplayProperties(object);

	if (item->containsComponentWithIdentifier(make_shared<string>(DMConstClassIdentifierItemProperties))) {
		auto objectItemProperties = DMUtils::getObjectItemProperties(item);
		auto itemEffect = objectItemProperties->getRangeRandomEffect();

		switch (objectItemProperties->type) {

			case synergyItem:
				gameplayProperties->addSynergy(itemEffect);
				return true;

			case supply:
				gameplayProperties->addHealth(itemEffect);
				return true;

			default:
				break;

		}
	}

	return false;
}