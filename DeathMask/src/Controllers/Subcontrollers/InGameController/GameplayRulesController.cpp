#include <ctime>
#include "GameplayRulesController.h"
#include <DeathMask/src/Utils/DMUtils.h>
#include <iostream>
#include <DeathMask/src/Const/DMConstClassIdentifiers.h>

using namespace DeathMaskGame;

GameplayRulesController::GameplayRulesController(shared_ptr<Objects> objects, shared_ptr<Object> mainCharacter, shared_ptr<GameplayRulesControllerDelegate> delegate)
{
    this->mainCharacter = mainCharacter;
    this->delegate = delegate;
    
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
	auto synergyTimerTimeout = 20;
	auto synergyDecrementFactor = 1;
	auto shouldDecrementSynergy = synergyTimer  > synergyTimerTimeout + previousSynergyTimer;

	auto copiedObjects = objects->copy();

	for (auto i = 0; i < copiedObjects->size(); i++)
	{
		auto object = copiedObjects->objectAtIndex(i);
		auto gameplayProperties = DMUtils::getObjectGameplayProperties(object);

		if (gameplayProperties->creatureType == CreatureType::living && shouldDecrementSynergy)
		{
			gameplayProperties->synergy -= synergyDecrementFactor;
		}
	}

	if (shouldDecrementSynergy)
	{
		previousSynergyTimer = synergyTimer;		
	}
    
    if (mainCharacter.get() == nullptr) {
        throw logic_error("Can't handle main character in gameplay rules controller, because it's null");
    }
    else {
        auto gameplayProperties = DMUtils::getObjectGameplayProperties(mainCharacter);
        if (gameplayProperties->isDead()) {
            delegate->gameplayRulesControllerMainCharacterDidDie(shared_from_this(), mainCharacter);
        }
    }
    
}

void GameplayRulesController::removeObject(shared_ptr<Object> object) {

	objects->removeObject(object);

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
				delegate->gameplayRulesControllerMainCharacterDidFoundDeathMask(shared_from_this()) ;
				break;
                
            case ItemType::count:
                
                throw logic_error("Can't handle \"count\" as objectItemProperties type in GameplayRulesController");
                
                break;

		}

		if (objectItemProperties->lockedByQuestItem == true && gameplayProperties->questItem.get() != nullptr)
		{
			gameplayProperties->questItem = nullptr;
		}
	}

	return result;
}
