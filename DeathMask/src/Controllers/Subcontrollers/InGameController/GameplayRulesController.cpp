#include <ctime>
#include "GameplayRulesController.h"
#include <DeathMask/src/Utils/DMUtils.h>
#include <iostream>

using namespace DeathMaskGame;

GameplayRulesController::GameplayRulesController(shared_ptr<Objects> objects) 
{
	if (objects.get() == nullptr)
	{
		throw logic_error("Can't initialize Gameplay Rules Controller with null objects pointer");
	}

	previousHungerTimer = 0;
	previousOxygenTimer = 0;

	this->objects = objects;
}

void GameplayRulesController::step()
{
	auto hungerTimer = std::time(nullptr);
	auto oxygenTimer = std::time(nullptr);

	auto shouldDecrementHunger = hungerTimer  > 80 + previousHungerTimer;
	auto shouldDecrementOxygen = oxygenTimer  > 20 + previousOxygenTimer;

	for (auto i = 0; i < objects->size(); i++)
	{
		auto object = objects->objectAtIndex(i);
		auto gameplayProperties = DMUtils::getObjectGameplayProperties(object);

		if (gameplayProperties->creatureType == CreatureType::living && shouldDecrementHunger)
		{
			auto hunger = gameplayProperties->getHunger();
			hunger -= 1;
			gameplayProperties->setHunger(hunger);
		}

		if (gameplayProperties->creatureType == CreatureType::living && shouldDecrementOxygen)
		{
			auto oxygen = gameplayProperties->getOxygen();
			oxygen -= 1;
			gameplayProperties->setOxygen(oxygen);
		}
	}

	if (shouldDecrementHunger)
	{
		previousHungerTimer = hungerTimer;		
	}

	if (shouldDecrementOxygen)
	{
		previousOxygenTimer = oxygenTimer;
	}
}

bool GameplayRulesController::objectTryingToUseItem(shared_ptr<Object> object, shared_ptr<Object> item)
{
	return false;
}