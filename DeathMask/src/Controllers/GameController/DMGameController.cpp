/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMGameController.cpp
 * Author: demensdeum
 * 
 * Created on April 16, 2017, 5:58 PM
 */

#include "DMGameController.h"

#include <ctime>
#include <iostream>

#include <FlameSteelEngineGameToolkit/IO/IOSystems/FSEGTIOGenericSystemParams.h>
#include <FlameSteelEngineGameToolkit/IO/AudioPlayer/FSEGTAudioPlayer.h>

#include <FlameSteelCore/FSCUtils.h>

#include <DeathMask/src/Const/DMConstStates.h>
#include <DeathMask/src/Const/DMConstIOSystem.h>

#include <DeathMask/src/Controllers/Subcontrollers/CreditsController/CreditsController.h>
#include <DeathMask/src/Controllers/Subcontrollers/InGameController/DMInGameController.h>
#include <DeathMask/src/Controllers/Subcontrollers/MenuController/MenuController.h>
#include <DeathMask/src/Controllers/Subcontrollers/GameOverController/GameOverController.h>
#include <DeathMask/src/Controllers/Subcontrollers/GameFinalController/GameFinalController.h>

#include <FlameSteelEngineGameToolkitFSGL/FSEGTIOFSGLSystem.h>

#define DEATHMASK_PLAY_MUSIC 1

DMGameController::DMGameController() {

    // random seed
    
    srand (time(NULL));
    
    // IO System
    
    auto ioSystemParams = make_shared<FSEGTIOGenericSystemParams>();
    ioSystemParams->title = FSCUtils::localizedString(make_shared<string>("Death Mask v0.5"));
    ioSystemParams->width = DMConstIOSystemScreenWidth;
    ioSystemParams->height = DMConstIOSystemScreenHeight;
    
    ioSystem = makeIOSystem();
    ioSystem->initialize(ioSystemParams);
        
#if DEATHMASK_PLAY_MUSIC == 1
	ioSystem->audioPlayer->play(make_shared<string>("data/com.demensdeum.deathmaskgame.dc117.audio.json"));
#endif

	auto companyLogoController = make_shared<CreditsController>();
	companyLogoController->logoPath = make_shared<string>("com.demensdeum.logo.png");
	setControllerForState(companyLogoController, DMStateCompanyLogo);

	auto flameSteelEngineController = make_shared<CreditsController>();
	flameSteelEngineController->logoPath = make_shared<string>("com.demensdeum.flamesteelengine.png");
	setControllerForState(flameSteelEngineController, DMStateFlameSteelEngineLogo);

	auto menuController = make_shared<MenuController>();
	setControllerForState(menuController, DMStateMenu);

	auto inGameController = make_shared<DMInGameController>();
	setControllerForState(inGameController, DMStateInGame);

	auto gameOverController = make_shared<GameOverController>();
	setControllerForState(gameOverController, DMStateGameOver);

	auto gameFinalController = make_shared<GameFinalController>();
	setControllerForState(gameFinalController, DMStateGameFinal);
}

shared_ptr<FSEGTIOSystem> DMGameController::makeIOSystem() {
    auto ioSystem = make_shared<FSEGTIOFSGLSystem>();
    return ioSystem;
}

void DMGameController::controllerDidFinish(Controller *controller, shared_ptr<string> message) {

    switch (state) {

      		case DMStateCompanyLogo:
			objectsContext->removeAllObjects();
            switchToState(DMStateFlameSteelEngineLogo);
            break; 
           
		case DMStateFlameSteelEngineLogo:
            objectsContext->removeAllObjects();
            switchToState(DMStateMenu);
			break;

		case DMStateMenu:
            ioSystem->materialLibrary->clear();
            objectsContext->removeAllObjects();
            switchToState(DMStateInGame);
			break;

        case DMStateInGame:

		if (message.get() == nullptr) {
			throw logic_error("INGAME CONTROLLER FINISHED WITHOUT MESSAGE, CAN'T CONTINUE");
		}

            ioSystem->materialLibrary->clear();
            objectsContext->removeAllObjects();

		if (message->compare("Game Over") == 0) {
	            switchToState(DMStateGameOver);
		}
		else if (message->compare("Game Final") == 0) {
	            switchToState(DMStateGameFinal);
		}

            break;

	case DMStateGameOver:
            ioSystem->materialLibrary->clear();
            objectsContext->removeAllObjects();
            switchToState(DMStateMenu);
            break;

	case DMStateGameFinal:
            ioSystem->materialLibrary->clear();
            objectsContext->removeAllObjects();
            switchToState(DMStateMenu);
            break;

    }
}

DMGameController::DMGameController(const DMGameController& ) {
}

DMGameController::~DMGameController() {
}
