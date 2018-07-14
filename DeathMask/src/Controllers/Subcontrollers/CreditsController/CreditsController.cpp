#include <FlameSteelEngineGameToolkitAlgorithms/Algorithms/MazeObjectGenerator/FSGTAMazeObjectGenerator.h>
#include <FlameSteelEngineGameToolkit/Controllers/FreeCameraController/FSEGTFreeCameraController.h>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>

#include "CreditsController.h"

using namespace DeathMaskGame;

void CreditsController::beforeStart() {

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

	auto serializedCardModelString = FSGTAMazeObjectGenerator::generatePlane(4, 2.28, make_shared<string>("com.demensdeum.logo.bmp"));

	companyLogo = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("Demensdeum Logo"),
            make_shared<string>("Demensdeum Logo"),
            shared_ptr<string>(),
            shared_ptr<string>(),
		serializedCardModelString,
            -2, -1.12, -2,
            1, 1, 1,
            0, 0, 0,
            0);    	

	brightness = FSEGTUtils::getObjectBrightness(companyLogo);
	brightness->floatNumber = 0;

	objectsContext->addObject(companyLogo);

	freeCameraController = make_shared<FSEGTFreeCameraController>(ioSystem->inputController, camera);
	freeCameraController->delegate = shared_from_this();

};

void CreditsController::step() {

	renderer->render(gameData);

	ioSystem->inputController->pollKey();

	if (ioSystem->inputController->isExitKeyPressed()) {

		ioSystem->stop();
		exit(0);

	}
	else if (freeCameraController.get() != nullptr)
	{
			freeCameraController->step();
	}

	if (brightness->floatNumber < 1 && waitCounter < 100)
	{
		brightness->floatNumber += 0.01;
	}
	else if (waitCounter <120)
	{
		waitCounter += 1;
	}
	else if (brightness->floatNumber > 0)
	{
		brightness->floatNumber -= 0.01;
	}
	objectsContext->updateObject(companyLogo);
}

void CreditsController::freeCameraControllerDidUpdateCamera(shared_ptr<FSEGTFreeCameraController> freeCameraController, shared_ptr<Object> camera) {

	objectsContext->updateObject(camera);

}