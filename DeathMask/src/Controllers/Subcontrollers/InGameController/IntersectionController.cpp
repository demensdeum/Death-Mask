#include "IntersectionController.h"

#include <iostream>

shared_ptr<Objects> IntersectionController::rayFromObjectIntersectsObjects(shared_ptr<Object> object, 
																				shared_ptr<ObjectsMap> objectsMap, 
																				shared_ptr<GameMap> gameMap, 
																				bool invertZ) {

		auto objects = make_shared<Objects>();

		auto position = FSEGTUtils::getObjectPosition(object)->copy();
		auto rotation = FSEGTUtils::getObjectRotation(object);

		for (int i = 0; i < 300; i++) {

		glm::mat4 matrix(1.0);

		matrix = glm::translate(matrix, glm::vec3(position->x, position->y, position->z));

		matrix = glm::rotate(matrix, rotation->x, glm::vec3(1.f, 0.f, 0.f));
		matrix = glm::rotate(matrix, rotation->y, glm::vec3(0.f, 1.f, 0.f));
		matrix = glm::rotate(matrix, rotation->z, glm::vec3(0.f, 0.f, 1.f));

			float step = invertZ ? 0.3 : -0.3;

			float x = 0;
			float y = 0;
			float z = step * i;

			matrix = glm::translate(matrix, glm::vec3(x, y, z));

			auto result = matrix * glm::vec4(0.f, 0.f, 0.f, 1.f);

			position->x = result.x;
			position->y = result.y;
			position->z = result.z;

			auto tileX = int(position->x);
			auto tileY = int(position->z);

			auto tile = gameMap->getTileIndexAtXY(tileX, tileY);

			if (tile == 1) {

				cout << "ray trace stop - wall" << endl;

				break;
			}

			cout << "check intersection" << endl;

			auto objectsIntersected = objectsMap->objectsAtXY(tileX, tileY);

			if (objectsIntersected.get() != nullptr) {

				for (auto objectIndex = 0; objectIndex < objectsIntersected->size(); objectIndex++) {
					auto object = objectsIntersected->objectAtIndex(objectIndex);
					auto uuid = object->uuid;

					if (objects->objectWithUUID(uuid).get() == nullptr) {
						objects->addObject(object);
					}
				}
			}
		}

	cout << "objects intersected number: " << objects->size() << endl;

	return objects;

}