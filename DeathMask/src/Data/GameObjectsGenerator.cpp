#include "GameObjectsGenerator.h"

#include <SDL2/SDL_image.h>
#include <DeathMask/src/Data/Components/Controls/ZombieControls/ZombieControls.h>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <FlameSteelEngineGameToolkit/Data/Components/Text/FSEGTText.h>
#include <DeathMask/src/Const/DMConstClassIdentifiers.h>
#include <DeathMask/src/Data/Components/Item/ItemProperties.h>
#include <FlameSteelCore/FSCUtils.h>
#include <DeathMask/src/Data/Components/GameplayProperties/DMGameplayProperties.h>
#include <string>
#include <iostream>
#include <FlameSteelEngineGameToolkitAlgorithms/Algorithms/MazeObjectGenerator/FSGTAMazeObjectGenerator.h>
#include <DeathMask/src/Const/Const.h>
#include <FlameSteelEngineGameToolkit/Const/FSEGTConst.h>
#include <FlameSteelEngineGameToolkit/Data/Components/Text/FSEGTText.h>

using namespace FlameSteelCore::Utils;
using namespace DeathMaskGame;

GameObjectsGenerator::GameObjectsGenerator() {
}

using namespace DeathMaskGame;
using namespace DeathMaskGame::Difficulty;

shared_ptr<Object> GameObjectsGenerator::generateRandomItem(enum Difficulty itemDifficulty, weak_ptr<MaterialLibrary> materialLibrary) {

	auto randomItemType = FSCUtils::FSCRandomInt(ItemType::count);

	if (randomItemType == deathMask) {
		auto luckyDay = FSCUtils::FSCRandomInt(10) == 3;
		if (luckyDay != true) {
			randomItemType = synergyItem;
		}
	}

	auto item = shared_ptr<Object>();

	switch (randomItemType)
	{

		case weapon:

			//cout << "Generate weapon item" << endl;

			item = generateWeapon(itemDifficulty, materialLibrary);
			break;

		case supply:

			//cout << "Generate supply item" << endl;

			item  = generateSupplyItem(itemDifficulty);
			break;

		case questItem:

			//cout << "Generate quest item" << endl;

			item = generateQuestItem(itemDifficulty);
			break;

		case synergyItem:

			//cout << "Generate synergy item" << endl;

			item = generateSynergyItem(itemDifficulty);
			break;

		case deathMask:

			//cout << "Generate death-mask item. yay!" << endl;

			item = generateDeathMask();
			break;

		case count:
			throw logic_error("Can't generate item with incorrect type");

	}

	return item;

}

shared_ptr<Object> GameObjectsGenerator::generateDeathMask() {

	auto firstNames = vector<string>{LocalizedString("Death-Mask")};
	auto secondNames = vector<string>{LocalizedString("")};
	auto type = ItemType::deathMask;

	return generateObject(type, Difficulty::hard, firstNames, secondNames, false, 0, 0);

}

shared_ptr<Object> GameObjectsGenerator::generateQuestItem(enum Difficulty difficulty) {

	auto firstNames = vector<string>{LocalizedString("Red"), LocalizedString("Yellow"), LocalizedString("Blue")};
	auto secondNames = vector<string>{LocalizedString("Card"), LocalizedString("Key")};
	auto type = ItemType::questItem;

	return generateObject(type, difficulty, firstNames, secondNames, false, 0, 0);

}

shared_ptr<SurfaceMaterial> GameObjectsGenerator::makeSurfaceMaterialWeaponHUD(shared_ptr<string> path, SDL_Rect rect, weak_ptr<MaterialLibrary> materialLibrary) {

	auto materialLibraryLocked = materialLibrary.lock();
	if (materialLibraryLocked.get() == nullptr) {
		throw logic_error("Material Library is null, can't get surface material");
	}

	auto surfaceMaterial = materialLibraryLocked->surfaceMaterialForPath(path);

	if (surfaceMaterial.get() == nullptr) {

		surfaceMaterial = FSEGTFactory::makeSurfaceMaterialComponent(1024, 1024);

		auto weaponSurface = IMG_Load(path->c_str());

		if (!weaponSurface) {
			//cout << "Can't load image at path: " << path->c_str() << endl;
			throw runtime_error("Can't load image for weapon hud in objects generator");
		}

		auto surface = surfaceMaterial->material->surface;

		SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format, 0, 0, 0, 1));
		SDL_BlitSurface(weaponSurface, nullptr, surface, &rect);
		SDL_FreeSurface(weaponSurface);

		surfaceMaterial->setInstanceIdentifier(make_shared<string>("Weapon HUD Image"));
		surfaceMaterial->setClassIdentifier(make_shared<string>("Weapon HUD Image"));

		surfaceMaterial->debugIdentifier = "WEAPON SURFACE MATERIAL";

		materialLibraryLocked->setSurfaceMaterialForPath(surfaceMaterial, path);
	}

	return surfaceMaterial;

}

shared_ptr<Object> GameObjectsGenerator::generateSkybox() {

	auto skyboxSerializedModel = FSGTAMazeObjectGenerator::generateSkybox(make_shared<string>("com.demensdeum.testenvironment.skybox.png"));

      auto skybox = FSEGTFactory::makeOnSceneObject(
													            make_shared<string>("dummy"),
													            make_shared<string>("dummy"),
													            shared_ptr<string>(),
													            shared_ptr<string>(),
															skyboxSerializedModel->serializedModelString(),
													            0, 0, 0,
													            1, 1, 1,
													            0, 0, 0,
													            0);   	

	skybox->setClassIdentifier(make_shared<string>("skybox"));
	skybox->setInstanceIdentifier(make_shared<string>(skybox->uuid));

	auto flagSkybox = FSEGTFactory::makeBooleanComponent();
	flagSkybox->setInstanceIdentifier(make_shared<string>(FSEGTConstComponentsFlagSkybox));
	flagSkybox->setClassIdentifier(make_shared<string>(FSEGTConstComponentsFlagSkybox));

	skybox->addComponent(flagSkybox);

	auto text = make_shared<FSEGTText>(make_shared<string>("Skybox"));
	text->setClassIdentifier(make_shared<string>(DMConstClassIdentifierLabel.c_str()));
	skybox->addComponent(text);

	return skybox;
}

shared_ptr<Object> GameObjectsGenerator::makeObject(ItemType type, 
															shared_ptr<string> name, 
															int minimalEffect,
															int maximalEffect,
															bool lockedByQuestItem) {

	auto serializedCardModel = FSGTAMazeObjectGenerator::generateCube(0, 0, make_shared<string>("com.demensdeum.testenvironment.crate.png"));

      auto item = FSEGTFactory::makeOnSceneObject(
													            make_shared<string>("dummy"),
													            make_shared<string>("dummy"),
													            shared_ptr<string>(),
													            shared_ptr<string>(),
															serializedCardModel->serializedModelString(),
													            0, 0, 0,
													            1, 1, 1,
													            0, 0, 0,
													            0);   	

	item->setClassIdentifier(make_shared<string>(DMConstClassIdentifierItem));
	item->setInstanceIdentifier(make_shared<string>(item->uuid));

	auto text = make_shared<FSEGTText>(name);
	text->setClassIdentifier(make_shared<string>(DMConstClassIdentifierLabel.c_str()));
	item->addComponent(text);

	auto itemProperties = make_shared<ItemProperties>(type, minimalEffect, maximalEffect, lockedByQuestItem);
	item->addComponent(itemProperties);

	return item;
}

shared_ptr<Object> GameObjectsGenerator::generateObject(ItemType type, enum Difficulty itemDiffuclty, vector<string>firstNames, vector<string>secondNames, bool lockedByQuestItem, int minimalEffect, int maximalEffect) {

	auto firstRandom = FSCUtils::FSCRandomInt(firstNames.size());
	auto secondRandom = FSCUtils::FSCRandomInt(secondNames.size());

	auto label = firstNames[firstRandom];
	label += " ";
	label += secondNames[secondRandom];

	auto name = make_shared<string>(label);

	auto item = makeObject(type, name, minimalEffect, maximalEffect, lockedByQuestItem);

	return item;
};

shared_ptr<Object> GameObjectsGenerator::generateEnemy(enum Difficulty enemyDifficulty, weak_ptr<MaterialLibrary> materialLibrary) {

	auto serializedCubeModel = FSGTAMazeObjectGenerator::generatePlane(1, 1, make_shared<string>("com.demensdeum.testenvironment.enemy.png"), -0.5, 0); // centered

      auto object = FSEGTFactory::makeOnSceneObject(
													            make_shared<string>("dummy"),
													            make_shared<string>("dummy"),
													            shared_ptr<string>(),
													            shared_ptr<string>(),
															serializedCubeModel->serializedModelString(),
													            0, 0, 0,
													            1, 1, 1,
													            0, 0, 0,
													            0);   

	object->setClassIdentifier(make_shared<string>(DMConstClassIdentifierEnemy));
	object->setInstanceIdentifier(make_shared<string>(object->uuid));
	
	auto text = make_shared<FSEGTText>(make_shared<string>("Enemy"));
	text->setClassIdentifier(make_shared<string>(DMConstClassIdentifierLabel.c_str()));
	object->addComponent(text);

	auto gameplayProperties = make_shared<DMGameplayProperties>();
	object->addComponent(gameplayProperties);

	auto zombieControls = make_shared<ZombieControls>(object);
	object->addComponent(zombieControls);

	auto hitboxRectangle = FSEGTFactory::makeRectangle(0, 0, 1, 1);
	hitboxRectangle->setClassIdentifier(make_shared<string>("Hitbox"));
	hitboxRectangle->setInstanceIdentifier(make_shared<string>("Hitbox"));
	object->addComponent(hitboxRectangle);

	auto weapon = generateWeapon(Difficulty::easy, materialLibrary);
	gameplayProperties->weapon = weapon;
    
	object->debugIdentifier = "Enemy";

	return object;

};

shared_ptr<Object> GameObjectsGenerator::generateSynergyItem(enum Difficulty synergyDifficulty) {

	auto firstNames = vector<string>{LocalizedString("Synergy"), LocalizedString("Synergy") };
	auto secondNames = vector<string>{LocalizedString("tank"), LocalizedString("cassete"), LocalizedString("tablet")};
	auto type = ItemType::synergyItem;

	return generateObject(type,  synergyDifficulty, firstNames, secondNames, false, 10, 30);

}

shared_ptr<Object> GameObjectsGenerator::generateWeapon(enum Difficulty weaponDifficulty, weak_ptr<MaterialLibrary> materialLibrary) {

    auto weaponType =  FSCUtils::FSCRandomInt(WeaponType::count);
    
    switch (weaponDifficulty) {
        
        case easy:
            
            break;
            
        case normal:
            
            break;
            
        case hard:
            
            break;
        
    }
    
	switch (weaponType) {

		case WeaponType::pistol:
			return makePistol(materialLibrary);

		case WeaponType::shotgun:
			return makeShotgun(materialLibrary);

		case WeaponType::uzi:
			return makeUzi(materialLibrary);

		case WeaponType::assaultRifle:
			return makeAssaultRifle(materialLibrary);

		case WeaponType::gsd:
			return makeGSD(materialLibrary);
	}

	throw logic_error("Can't generate weapon - incorrect weapon type");

};

shared_ptr<Object> GameObjectsGenerator::generateSupplyItem(enum Difficulty supplyItemDifficulty) {

	auto firstNames = vector<string>{LocalizedString("VitaCom"), LocalizedString("Human Compatible Nanobots"), LocalizedString("Astra-Life")};
	auto secondNames = vector<string>{LocalizedString("painkiller"), LocalizedString("medkit"), LocalizedString("first aid")};
	auto type = ItemType::supply;

	return generateObject(type, supplyItemDifficulty, firstNames, secondNames, false, 10, 30);

};

shared_ptr<Object> GameObjectsGenerator::makePistol(weak_ptr<MaterialLibrary> materialLibrary) {

	auto name = make_shared<string>(LocalizedString("Pistol"));
	auto type = ItemType::weapon;
	auto minimalEffect = 5;
	auto maximalEffect = 10;
	auto lockedByQuestItem = false;

	auto item = makeObject(type, name, minimalEffect, maximalEffect, lockedByQuestItem);

	SDL_Rect weaponRect;
	weaponRect.x = 356;
	weaponRect.y = 382;
	weaponRect.w = 256;
	weaponRect.h = 195;

	auto path = make_shared<string>("data/com.demensdeum.pistol.hud.keepsize.png");
	auto hudImage = makeSurfaceMaterialWeaponHUD(path, weaponRect, materialLibrary);
	item->addComponent(hudImage);

	return item;

};

shared_ptr<Object> GameObjectsGenerator::makeShotgun(weak_ptr<MaterialLibrary> materialLibrary) {

	auto name = make_shared<string>(LocalizedString("Shotgun"));
	auto type = ItemType::weapon;
	auto minimalEffect = 5;
	auto maximalEffect = 10;
	auto lockedByQuestItem = false;

	auto item = makeObject(type, name, minimalEffect, maximalEffect, lockedByQuestItem);

	SDL_Rect weaponRect;
	weaponRect.x = 356;
	weaponRect.y = 382;
	weaponRect.w = 256;
	weaponRect.h = 195;

	auto path = make_shared<string>("data/com.demensdeum.shotgun.hud.keepsize.png");
	auto hudImage = makeSurfaceMaterialWeaponHUD(path, weaponRect, materialLibrary);
	item->addComponent(hudImage);

	return item;

};

shared_ptr<Object> GameObjectsGenerator::makeUzi(weak_ptr<MaterialLibrary> materialLibrary) {

	auto name = make_shared<string>(LocalizedString("Uzi"));
	auto type = ItemType::weapon;
	auto minimalEffect = 5;
	auto maximalEffect = 10;
	auto lockedByQuestItem = false;

	auto item = makeObject(type, name, minimalEffect, maximalEffect, lockedByQuestItem);

	SDL_Rect weaponRect;
	weaponRect.x = 606;
	weaponRect.y = 382;
	weaponRect.w = 256;
	weaponRect.h = 195;

	auto path = make_shared<string>("data/com.demensdeum.uzi.hud.keepsize.png");
	auto hudImage = makeSurfaceMaterialWeaponHUD(path, weaponRect, materialLibrary);
	item->addComponent(hudImage);

	return item;

};

shared_ptr<Object> GameObjectsGenerator::makeAssaultRifle(weak_ptr<MaterialLibrary> materialLibrary) {

	auto name = make_shared<string>(LocalizedString("Assault Rifle"));
	auto type = ItemType::weapon;
	auto minimalEffect = 5;
	auto maximalEffect = 10;
	auto lockedByQuestItem = false;

	auto item = makeObject(type, name, minimalEffect, maximalEffect, lockedByQuestItem);

	SDL_Rect weaponRect;
	weaponRect.x = 580;
	weaponRect.y = 382;
	weaponRect.w = 256;
	weaponRect.h = 195;

	auto path = make_shared<string>("data/com.demensdeum.assaultrifle.hud.keepsize.png");
	auto hudImage = makeSurfaceMaterialWeaponHUD(path, weaponRect, materialLibrary);
	item->addComponent(hudImage);

	return item;
};

shared_ptr<Object> GameObjectsGenerator::makeGSD(weak_ptr<MaterialLibrary> materialLibrary) {

	auto name = make_shared<string>(LocalizedString("GSD-4000"));
	auto type = ItemType::weapon;
	auto minimalEffect = 5;
	auto maximalEffect = 10;
	auto lockedByQuestItem = false;

	auto item = makeObject(type, name, minimalEffect, maximalEffect, lockedByQuestItem);

	SDL_Rect weaponRect;
	weaponRect.x = 436;
	weaponRect.y = 382;
	weaponRect.w = 256;
	weaponRect.h = 195;

	auto path = make_shared<string>("data/com.demensdeum.gsd.hud.keepsize.png");
	auto hudImage = makeSurfaceMaterialWeaponHUD(path, weaponRect, materialLibrary);
	item->addComponent(hudImage);

	return item;

};
