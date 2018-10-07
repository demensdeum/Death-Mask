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

UseItemResultType GameplayRulesController::objectTryingToUseItem(shared_ptr<Object> object, shared_ptr<Object> item)
{
	auto gameplayProperties = DMUtils::getObjectGameplayProperties(object);

	UseItemResultType result = cant;

	if (item->containsComponentWithIdentifier(make_shared<string>(DMConstClassIdentifierItemProperties))) {
		auto objectItemProperties = DMUtils::getObjectItemProperties(item);
		auto itemEffect = objectItemProperties->getRangeRandomEffect();

		if (objectItemProperties->lockedByQuestItem == true && gameplayProperties->questItem.get() == nullptr)
		{
			cout << "Can't pickup item - quest item required to unlock" << endl;
			return questItemNeeded;
		}

		switch (objectItemProperties->type) {

			case synergyItem:

				gameplayProperties->addSynergy(itemEffect);
				result = picked;
				break;

			case supply:
				gameplayProperties->addHealth(itemEffect);
				result = picked;
				break;

			case questItem:
				gameplayProperties->questItem = item;
				result = picked;
				break;

			case weapon:
				gameplayProperties->weapon = item;
				result = picked;
				break;

			case deathMask:
				cout << "YOU FOUND DEATH-MASK WOW! THE END" << endl;
				gameplayProperties->questItem = item;
				result = picked;
				break;

		}

		if (objectItemProperties->lockedByQuestItem == true && gameplayProperties->questItem.get() != nullptr)
		{
			gameplayProperties->questItem = nullptr;
		}
	}

	return result;
}