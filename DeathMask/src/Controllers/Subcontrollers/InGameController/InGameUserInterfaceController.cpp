#include "InGameUserInterfaceController.h"

#include <glm/gtc/matrix_transform.hpp>
#include <FlameSteelCore/Objects.h>
#include <DeathMask/src/Utils/DMUtils.h>
#include <DeathMask/src/Const/DMConstClassIdentifiers.h>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <FlameSteelEngineGameToolkit/Const/FSEGTConst.h>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <FlameSteelEngineGameToolkitAlgorithms/Algorithms/MazeObjectGenerator/FSGTAMazeObjectGenerator.h>

using namespace DeathMaskGame;

InGameUserInterfaceController::InGameUserInterfaceController(shared_ptr<Object> camera,
																			shared_ptr<DMGameplayProperties> gameplayProperties,
																				shared_ptr<InGameUserInterfaceControllerDataSource> dataSource) {
	this->camera = camera;
	this->gameplayProperties = gameplayProperties;
	this->dataSource = dataSource;

	auto flag2D = FSEGTFactory::makeBooleanComponent();
	flag2D->setInstanceIdentifier(make_shared<string>(FSEGTConstComponentsFlag2D));
	flag2D->setClassIdentifier(make_shared<string>(FSEGTConstComponentsFlag2D));

	auto uiPlane = FSGTAMazeObjectGenerator::generatePlane(1.2, 1.2, make_shared<string>("com.uitest.remove.bmp"));

	uiObject = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("UI Plane"),
            make_shared<string>("UI Plane"),
            shared_ptr<string>(),
            shared_ptr<string>(),
		uiPlane->serializedModelString(),
            -0.2, -0.08, -0.6,
            1, 1, 1,
            0, 0, 0,
            0);    	

	uiObject->addComponent(flag2D);

	auto text = make_shared<FSEGTText>(make_shared<string>("UI Object"));
	text->setClassIdentifier(make_shared<string>(DMConstClassIdentifierLabel.c_str()));
	uiObject->addComponent(text);

	surfaceMaterial = FSEGTFactory::makeSurfaceMaterialComponent(1024, 1024);
	uiObject->addComponent(surfaceMaterial);

}

void InGameUserInterfaceController::step() {

	auto surface = surfaceMaterial->surface;
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 0, 255));

	if (dataSource.get() == nullptr)
	{
		throw logic_error("Data source for in game user interface controller must be provided");
	}

	auto objects = dataSource->objectsForInGameUserInterfaceController(shared_from_this());
	string objectsString = "";
	
	if (objects.get() != nullptr)
	{
		for (int i = 0; i < objects->size(); i++)
		{
			auto object = objects->objectAtIndex(i);
			auto label = DMUtils::getObjectLabel(object);
			objectsString += ", ";
		} 

		auto size = objects->size();
		objectsString += std::to_string(size);
	}

	if (objectsString.length() < 1)
	{
		objectsString = "<No objects>";
	}

	char buffer[1024];
	sprintf(buffer, "Name: Seeker\nHealth: %d/%d\nSynergy: %d/%d\nWeapon: <None>\nObjects: %s", 
					gameplayProperties->health, gameplayProperties->healthMax, 
					gameplayProperties->synergy, gameplayProperties->synergyMax,
					objectsString.c_str());

	buffer[1023] = 0;

	//text->text = make_shared<string>(buffer);

	auto cameraPosition = FSEGTUtils::getObjectPosition(camera);

	if (cameraPosition.get() == nullptr) {
		throw logic_error("camera position is null");
	}
	
	{
		auto position = FSEGTUtils::getObjectPosition(camera)->copy();
		auto rotation = FSEGTUtils::getObjectRotation(camera);

		glm::mat4 matrix(1.0);

		matrix = glm::translate(matrix, glm::vec3(position->x, position->y, position->z));

		matrix = glm::rotate(matrix, rotation->x, glm::vec3(1.f, 0.f, 0.f));
		matrix = glm::rotate(matrix, rotation->y, glm::vec3(0.f, 1.f, 0.f));
		matrix = glm::rotate(matrix, rotation->z, glm::vec3(0.f, 0.f, 1.f));

		matrix = glm::translate(matrix, glm::vec3(-0.6, -0.86, -0.6));

		auto result = matrix * glm::vec4(0.f, 0.f, 0.f, 1.f);

		position->x = result.x;
		position->y = result.y;
		position->z = result.z;

		FSEGTUtils::getObjectPosition(uiObject)->populate(position);
		//FSEGTUtils::getObjectRotation(uiObject)->y += 0.1;
		FSEGTUtils::getObjectRotation(uiObject)->populate(rotation);
	}

}

shared_ptr<Objects> InGameUserInterfaceControllerDataSource::objectsForInGameUserInterfaceController(shared_ptr<InGameUserInterfaceController> inGameUserInterfaceController) {

	return shared_ptr<Objects>();

}