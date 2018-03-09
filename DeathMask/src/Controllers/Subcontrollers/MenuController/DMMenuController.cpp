#include <FlameSteelEngineGameToolkit/IO/Input/FSEGTInputController.h>
#include "DMMenuController.h" 

#include <iostream>
#include <chrono>
#include <thread>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>

void DMMenuController::beforeStart() {

	    auto cameraObject = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("camera"),
            make_shared<string>("camera"),
            make_shared<string>(),
            make_shared<string>(),
            0, 0, 0,
            1, 1, 1,
            0, 0, 0,
            0);    
    
    	      city = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("scene object"),
            make_shared<string>("revil"),
            make_shared<string>(),
            make_shared<string>("./data/graphics/models/maps/corruptedCity/corruptedCity"),
		0,0,0,
            1, 1, 1,
		0,0,0,
            0);    
    
    objectsContext->addObject(cameraObject);      
    objectsContext->addObject(city);

}

void DMMenuController::step() {

	for(auto i = 0; i < 6000; i++)
	{
		renderer->render(this->gameData);
		std::this_thread::sleep_for(0.01s);

        ioSystem->inputController->pollKey();

        if (ioSystem->inputController->isExitKeyPressed()) {

		cout << "Bye-Bye!" << endl;
		exit(0);

		}
      }
  
	cout << "Corrupted City Ended" << endl;

	exit(0);
}