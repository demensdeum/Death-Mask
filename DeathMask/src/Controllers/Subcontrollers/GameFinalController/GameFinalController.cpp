#include "GameFinalController.h"
#include <FlameSteelEngineGameToolkitAlgorithms/Algorithms/MazeObjectGenerator/FSGTAMazeObjectGenerator.h>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <iostream>

using namespace DeathMaskGame;

void GameFinalController::beforeStart() {

	cameraUpdated = false;
	cooldownTimer = 0;

	camera = FSEGTFactory::makeOnSceneObject(
      															make_shared<string>("camera"),
													           	make_shared<string>("camera"),
													           	shared_ptr<string>(),
															shared_ptr<string>(),
															shared_ptr<string>(),
													            0, 0, 0,
													            1, 1, 1,
													            0, 0, 0,
													            0);   

	auto gameOverCard = FSGTAMazeObjectGenerator::generatePlane(4, 2.28, make_shared<string>("com.demensdeum.deathmaskgame.gamefinal.png"));

	auto gameOverLogo = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("Demensdeum Logo"),
            make_shared<string>("Demensdeum Logo"),
            shared_ptr<string>(),
            shared_ptr<string>(),
		gameOverCard->serializedModelString(),
            -2, -1.12, -2,
            1, 1, 1,
            0, 0, 0,
            0);    	

	objectsContext->addObject(gameOverLogo);
};

void GameFinalController::step() {

     if (cameraUpdated == false) {
         objectsContext->updateObject(camera);
         cameraUpdated = true;
     }

	renderer->render(gameData);

	auto inputController = ioSystem->inputController;

	inputController->pollKey();

	if (inputController->isExitKeyPressed()) {

#ifndef __EMSCRIPTEN__
		cout << "Bye-Bye!" << endl;
		ioSystem->stop();
		exit(0);
#endif

	}
	else if (cooldownTimer < 80) {
		cooldownTimer++;
	}
	else if (inputController->isShootKeyPressed()) {
		notifyListenerAboutControllerDidFinish(this);
	}

	cout << "Game Over Controller step" << endl;

};