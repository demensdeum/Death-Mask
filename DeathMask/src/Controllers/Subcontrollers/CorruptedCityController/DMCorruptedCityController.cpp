#include "DMCorruptedCityController.h" 

#include <iostream>
#include <chrono>
#include <thread>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>

void DMCorruptedCityController::beforeStart() {

	    auto cameraObject = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("camera"),
            make_shared<string>("camera"),
            make_shared<string>(),
            make_shared<string>(),
            0, 0, 0,
            1, 1, 1,
            0, 0, 0,
            0);    
    
    auto revil = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("scene object"),
            make_shared<string>("revil"),
            make_shared<string>(),
            make_shared<string>("./data/graphics/models/maps/corruptedCity/corruptedCity"),
		0,0,0,
            1, 1, 1,
		0,0,0,
            0);    
    
    objectsContext->addObject(cameraObject);      
    objectsContext->addObject(revil);

}

void DMCorruptedCityController::step() {

    renderer->render(this->gameData);

std::this_thread::sleep_for(1s);

        objectsContext->removeAllObjects();
        
	cout << "Corrupted City Ended" << endl;

	exit(0);
}