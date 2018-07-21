#include "MenuController.h"

#include <FlameSteelEngineGameToolkitAlgorithms/Algorithms/MazeObjectGenerator/FSGTAMazeObjectGenerator.h>
#include <FlameSteelEngineGameToolkit/Controllers/FreeCameraController/FSEGTFreeCameraController.h>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <FlameSteelCore/FSCUtils.h>

using namespace DeathMaskGame;

void MenuController::beforeStart() {

	auto serializedCardModelString = FSGTAMazeObjectGenerator::generatePlane(4, 2.28, make_shared<string>("com.demensdeum.deathmaskgame.sky.bmp"));

	sky = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("Demensdeum Logo"),
            make_shared<string>("Demensdeum Logo"),
            shared_ptr<string>(),
            shared_ptr<string>(),
		serializedCardModelString,
            -2, -1.12, -2,
            1, 1, 1,
            0, 0, 0,
            0);

	brightness = FSEGTUtils::getObjectBrightness(sky);
	brightness->floatNumber = 0;

	objectsContext->addObject(sky);

	auto skyscraperModelString = FSGTAMazeObjectGenerator::generateBox(0.2, 1, 0.2, 10, 3, make_shared<string>("com.demensdeum.deathmaskgame.skyscraper.bmp"));

	for (auto i = 0; i < 5; i++)
	{

		float skyscraperY = -0.67  - FSCUtils::FSCRandomInt(4) / 10.f;
		float skyscraperZ = -1.2 + FSCUtils::FSCRandomInt(15) / 10.f;

		auto skyscraper = FSEGTFactory::makeOnSceneObject(
	      	      make_shared<string>("Skyscraper"),
      		      make_shared<string>("Skyscraper"),
	            shared_ptr<string>(),
	            shared_ptr<string>(),
			skyscraperModelString,
	            i-2, skyscraperY, skyscraperZ,
	            1, 1, 1,
	            -0.8, 0, 0,
	            0);

		FSEGTUtils::getObjectBrightness(skyscraper)->floatNumber = 0;

		objectsContext->addObject(skyscraper);

		skyscrapers.push_back(skyscraper);
	}

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

	freeCameraController = make_shared<FSEGTFreeCameraController>(ioSystem->inputController, camera);
	freeCameraController->delegate = shared_from_this();

}

void MenuController::freeCameraControllerDidUpdateCamera(shared_ptr<FSEGTFreeCameraController> freeCameraController, shared_ptr<Object> camera) {

	objectsContext->updateObject(camera);

}

 void MenuController::step() {

	if (freeCameraController.get() != nullptr)
	{
		freeCameraController->step();
	}

	renderer->render(gameData);

	ioSystem->inputController->pollKey();

	if (ioSystem->inputController->isExitKeyPressed()) 
	{
		ioSystem->stop();
		exit(0);
	}

	if (brightness->floatNumber < 1.0)
	{
		brightness->floatNumber += 0.01;
	}

	objectsContext->updateObject(sky);

	for (auto skyscraper : skyscrapers)
	{

		auto skyscraperPosition = FSEGTUtils::getObjectPosition(skyscraper);

		if (skyscraperPosition->x < 3)
		{
			skyscraperPosition->x += 0.001;
		}
		else
		{
			skyscraperPosition->x -= 5.3;

			skyscraperPosition->y = -0.67  - FSCUtils::FSCRandomInt(4) / 10.f;
			skyscraperPosition->z = -1.2 + FSCUtils::FSCRandomInt(15) / 10.f;	

		}

		auto skyscraperBrightness = FSEGTUtils::getObjectBrightness(skyscraper);

		if (skyscraperBrightness->floatNumber < 1.0)
		{
			skyscraperBrightness->floatNumber += 0.01;
		}

		objectsContext->updateObject(skyscraper);
	}
}