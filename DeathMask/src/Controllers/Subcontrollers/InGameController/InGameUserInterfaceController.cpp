#include "InGameUserInterfaceController.h"

#include <SDL2/SDL_image.h>
#include <sstream>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <FlameSteelCore/Objects.h>
#include <DeathMask/src/Utils/DMUtils.h>
#include <DeathMask/src/Const/DMConstClassIdentifiers.h>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <FlameSteelEngineGameToolkit/Const/FSEGTConst.h>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <FlameSteelEngineGameToolkitAlgorithms/Algorithms/MazeObjectGenerator/FSGTAMazeObjectGenerator.h>

using namespace DeathMaskGame;
using namespace std;

InGameUserInterfaceController::InGameUserInterfaceController(shared_ptr<Object> camera,
																			shared_ptr<DMGameplayProperties> gameplayProperties,
																				shared_ptr<InGameUserInterfaceControllerDataSource> dataSource) {
	this->camera = camera;
	this->gameplayProperties = gameplayProperties;
	this->dataSource = dataSource;

	auto flag2D = FSEGTFactory::makeBooleanComponent();
	flag2D->setInstanceIdentifier(make_shared<string>(FSEGTConstComponentsFlag2D));
	flag2D->setClassIdentifier(make_shared<string>(FSEGTConstComponentsFlag2D));

	auto uiPlane = FSGTAMazeObjectGenerator::generatePlane(1.2, 1.2, make_shared<string>("com.uitest.remove.png"));

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

	if(TTF_Init() != 0) {
		printf("TTF_Init: %s\n", TTF_GetError());
		throw runtime_error("Can't load SDL2 TTF");
	}

	font = TTF_OpenFont("data/com.demensdeum.deathmask.crystal.font.ttf", 16);

	if(!font) {
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		runtime_error("TTF Can't load font");
	}

	aimSurface = IMG_Load("data/com.demensdeum.hud.aim.png");
}

void InGameUserInterfaceController::step() {

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
			objectsString += *label->text;
			objectsString += ", ";
		} 

		auto size = objects->size();
		objectsString += std::to_string(size);
	}

	if (objectsString.length() < 1)
	{
		objectsString = "<No objects>";
	}

	auto screenMessage = dataSource->messageForInGameUserInterfaceController(shared_from_this());

	char buffer[1024];
	sprintf(buffer, "Death Mask 0.3 (Alpha)\nName: %s\nHealth: %d/%d\nSynergy: %d/%d\nWeapon: %s\nQuest Item: %s\nObjects: %s\n%s", 
					gameplayProperties->name->c_str(),
					gameplayProperties->health, gameplayProperties->healthMax, 
					gameplayProperties->synergy, gameplayProperties->synergyMax,
					gameplayProperties->weaponLabel()->c_str(), gameplayProperties->questItemLabel()->c_str(),
					objectsString.c_str(), screenMessage->c_str());

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
		FSEGTUtils::getObjectRotation(uiObject)->populate(rotation);
	}

	auto bufferString = string(buffer);

	std::istringstream iss(bufferString);

	if (bufferString.compare(previousRenderedString) != 0) {

	auto surface = surfaceMaterial->material->surface;
	SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format, 0, 0, 0, 1));

	auto weapon = gameplayProperties->weapon;

	if (weapon) {
		auto weaponSurfaceMaterial = DMUtils::getWeaponHUDImageSurfaceMaterial(weapon);
		if (weaponSurfaceMaterial) {
			auto material = weaponSurfaceMaterial->material;
			if (material) {
				auto weaponSurface = material->surface;
				SDL_BlitSurface(weaponSurface, nullptr, surface, nullptr);
			}
			else {
				//cout << "There is weapon, there is material, but no surface to render" << endl;
			}
		}
		else {
			//cout << "There is weapon, but no material surface to render" << endl;
		}
	}

	SDL_Color color = { 255, 255, 255, 255 };

	// SDL TTF on OS X mojave crash workaround - wrapped rendering simulation

	auto lineIndex = 0;

	for (std::string line; std::getline(iss, line); ) {
		
		lineIndex+= 1;
		auto uiText = TTF_RenderText_Solid(font, line.c_str(), color);
		SDL_Rect destinationRect;
		destinationRect.x = 20;
		destinationRect.y = lineIndex * 20;
		destinationRect.w = uiText->w;
		destinationRect.h = uiText->h;
		SDL_BlitSurface(uiText, nullptr, surface, &destinationRect);
		SDL_FreeSurface(uiText);
	
	}

	{
		SDL_Rect sourceRect = aimSurface->clip_rect;
		SDL_Rect destinationRect = sourceRect;
		destinationRect.x = (surface->w / 2)  - aimSurface->w / 2;
		destinationRect.y = (surface->h / 4) ;

		SDL_BlitSurface(aimSurface, nullptr, surface, &destinationRect);
	}
	
	previousRenderedString = bufferString;
	surfaceMaterial->material->needsUpdate = true;

	}

}

shared_ptr<string> InGameUserInterfaceControllerDataSource::messageForInGameUserInterfaceController(shared_ptr<InGameUserInterfaceController> inGameUserInterfaceController) {

	return make_shared<string>();

}

shared_ptr<Objects> InGameUserInterfaceControllerDataSource::objectsForInGameUserInterfaceController(shared_ptr<InGameUserInterfaceController> inGameUserInterfaceController) {

	return shared_ptr<Objects>();

}

InGameUserInterfaceController::~InGameUserInterfaceController() {

	if (aimSurface != nullptr) {
		SDL_FreeSurface(aimSurface);
	}

	if (font != nullptr) {
		TTF_CloseFont(font);
	}
};
