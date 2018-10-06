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


#define DEATHMASK_IO_SYSTEM 0

#if DEATHMASK_IO_SYSTEM == 0
#include <FlameSteelEngineGameToolkitFSGL/FSEGTIOFSGLSystem.h>
#elif DEATHMASK_IO_SYSTEM ==1
#include <FlameSteelEngineGameToolkitNcurses/FSEGTIONcursesSystem.h>
#endif

DMGameController::DMGameController() {
    
    // random seed
    
    srand (time(NULL));
    
    // IO System
    
    auto ioSystemParams = make_shared<FSEGTIOGenericSystemParams>();
    ioSystemParams->title = FSCUtils::localizedString(make_shared<string>("Death Mask"));
    ioSystemParams->width = DMConstIOSystemScreenWidth;
    ioSystemParams->height = DMConstIOSystemScreenHeight;
    
    ioSystem = this->makeIOSystem();
    ioSystem->initialize();
        
	ioSystem->audioPlayer->play(make_shared<string>("data/com.demensdeum.deathmaskgame.dc113.ogg"));

	auto companyLogoController = make_shared<CreditsController>();
	companyLogoController->logoPath = make_shared<string>("com.demensdeum.logo.bmp");
	setControllerForState(companyLogoController, DMStateCompanyLogo);

	auto flameSteelEngineController = make_shared<CreditsController>();
	flameSteelEngineController->logoPath = make_shared<string>("com.demensdeum.flamesteelengine.bmp");
	setControllerForState(flameSteelEngineController, DMStateFlameSteelEngineLogo);

	auto menuController = make_shared<MenuController>();
	setControllerForState(menuController, DMStateMenu);

	auto inGameController = make_shared<DMInGameController>();
	setControllerForState(inGameController, DMStateInGame);
}

shared_ptr<FSEGTIOSystem> DMGameController::makeIOSystem() {

#if DEATHMASK_IO_SYSTEM == 0
    auto ioSystem = make_shared<FSEGTIOFSGLSystem>();    
#elif DEATHMASK_IO_SYSTEM ==1
    auto ioSystem = make_shared<FSEGTIONcursesSystem>();    
#endif    

    return ioSystem;
}

void DMGameController::controllerDidFinish(Controller *controller) {

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
				objectsContext->removeAllObjects();
            		switchToState(DMStateInGame);		
			break;

	default:
		cout << "State: " << state << endl;
		throw logic_error("Unhandled state to switch");
    }
}

DMGameController::DMGameController(const DMGameController& ) {
}

DMGameController::~DMGameController() {
}