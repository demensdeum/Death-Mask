#include "MenuController.h"

#include <FlameSteelEngineGameToolkit/Const/FSEGTConst.h>
#include <FlameSteelEngineGameToolkitAlgorithms/Algorithms/MazeObjectGenerator/FSGTAMazeObjectGenerator.h>
#include <FlameSteelEngineGameToolkit/Controllers/FreeCameraController/FSEGTFreeCameraController.h>
#include <FlameSteelEngineGameToolkitAlgorithms/Controllers/CursorController/CursorController.h>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <FlameSteelCore/FSCUtils.h>

using namespace FlameSteelEngine::GameToolkit::Algorithms;
using namespace DeathMaskGame;

void MenuController::beforeStart() {

	auto flag2D = FSEGTFactory::makeBooleanComponent();
	flag2D->setInstanceIdentifier(make_shared<string>(FSEGTConstComponentsFlag2D));
	flag2D->setClassIdentifier(make_shared<string>(FSEGTConstComponentsFlag2D));

	auto serializedCardModelString = FSGTAMazeObjectGenerator::generatePlane(4, 2.28, make_shared<string>("com.demensdeum.deathmaskgame.sky.png"));

	sky = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("Demensdeum Logo"),
            make_shared<string>("Demensdeum Logo"),
            shared_ptr<string>(),
            shared_ptr<string>(),
	    serializedCardModelString->serializedModelString(),
            -2, -1.12, -2,
            1, 1, 1,
            0, 0, 0,
            0);

	brightness = FSEGTUtils::getObjectBrightness(sky);
	brightness->floatNumber = 0;

	objectsContext->addObject(sky);

	auto skyscraperModelString = FSGTAMazeObjectGenerator::generateBox(0.2, 1, 0.2, 4, 18, make_shared<string>("com.demensdeum.deathmaskgame.skyscraper.png"));

	for (auto i = 0; i < 5; i++)
	{

		float skyscraperY = -0.67  - FSCUtils::FSCRandomInt(4) / 10.f;
		float skyscraperZ = -1.15 + FSCUtils::FSCRandomInt(15) / 10.f;

		auto skyscraper = FSEGTFactory::makeOnSceneObject(
	      	      make_shared<string>("Skyscraper"),
      		      make_shared<string>("Skyscraper"),
	            shared_ptr<string>(),
	            shared_ptr<string>(),
			 skyscraperModelString->serializedModelString(),
	            i-2, skyscraperY, skyscraperZ,
	            1, 1, 1,
	            -0.8, 0, 0,
	            0);

		FSEGTUtils::getObjectBrightness(skyscraper)->floatNumber = 0;

		objectsContext->addObject(skyscraper);

		skyscrapers.push_back(skyscraper);
	}

	auto serializedGameLogoModel = FSGTAMazeObjectGenerator::generatePlane(0.336, 0.4, make_shared<string>("com.demensdeum.deathmaskgame.logo.png"));

	gameLogo = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("Game Logo"),
            make_shared<string>("Game Logo"),
            shared_ptr<string>(),
            shared_ptr<string>(),
		serializedGameLogoModel->serializedModelString(),
            -0.2, -0.08, -0.6,
            1, 1, 1,
            0, 0, 0,
            0);    	

	gameLogo->addComponent(flag2D);

	logoBrightness = FSEGTUtils::getObjectBrightness(gameLogo);
	logoBrightness->floatNumber = 0;

	objectsContext->addObject(gameLogo);

	auto serializedCursorModel = FSGTAMazeObjectGenerator::generatePlane(0.018, 0.025, make_shared<string>("com.demensdeum.deathmaskgame.cursor.png"));

	cursor = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("Game Cursor"),
            make_shared<string>("Game Cursor"),
            shared_ptr<string>(),
            shared_ptr<string>(),
		serializedCursorModel->serializedModelString(),
            -0.2, -0.08, -0.4,
            1, 1, 1,
            0, 0, 0,
            0);    	

	cursor->addComponent(flag2D);
	objectsContext->addObject(cursor);

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

	cursorController = make_shared<CursorController>(cursor, ioSystem->inputController);
	cursorController->delegate = shared_from_this();

}

void MenuController::freeCameraControllerDidUpdateCamera(shared_ptr<FSEGTFreeCameraController> freeCameraController, shared_ptr<Object> camera) {

	//objectsContext->updateObject(camera);

}

void MenuController::cursorControllerDidUpdateCursor(shared_ptr<CursorController> cursorController, shared_ptr<Object> cursor) {

	objectsContext->updateObject(cursor);

}

 void MenuController::step() {

	if (cursorController.get() != nullptr)
	{
		cursorController->step();
	}

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
 	else if (ioSystem->inputController->isShootKeyPressed()) {
		
		notifyListenerAboutControllerDidFinish(this);
		return;
	}

	if (brightness->floatNumber < 1.0)
	{
		brightness->floatNumber += 0.01;
	}

	objectsContext->updateObject(sky);

	if (logoBrightness->floatNumber < 1.0)
	{
		logoBrightness->floatNumber += 0.01;
	}

	objectsContext->updateObject(gameLogo);

	for (auto skyscraper : skyscrapers)
	{

		auto skyscraperPosition = FSEGTUtils::getObjectPosition(skyscraper);

		if (skyscraperPosition->x < 3)
		{
			skyscraperPosition->x += 0.00008;
		}
		else
		{
			skyscraperPosition->x -= 5.3;

			skyscraperPosition->y = -0.67  - FSCUtils::FSCRandomInt(4) / 10.f;
			skyscraperPosition->z = -1.15 + FSCUtils::FSCRandomInt(15) / 10.f;	

		}

		auto skyscraperBrightness = FSEGTUtils::getObjectBrightness(skyscraper);

		if (skyscraperBrightness->floatNumber < 1.0)
		{
			skyscraperBrightness->floatNumber += 0.01;
		}

		objectsContext->updateObject(skyscraper);
	}
}