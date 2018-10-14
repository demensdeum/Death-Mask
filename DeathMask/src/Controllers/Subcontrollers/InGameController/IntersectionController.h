#ifndef DEATHMASK_INTERSECTION_CONTROLLER_H_
#define DEATHMASK_INTERSECTION_CONTROLLER_H_

#include <memory>
#include <FlameSteelCore/Object.h>
#include <FlameSteelCore/Objects.h>
#include <glm/gtc/matrix_transform.hpp>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <FlameSteelEngineGameToolkit/Data/ObjectsMap/ObjectsMap.h>
#include <FlameSteelEngineGameToolkit/Data/Components/Vector/FSEGTVector.h>
#include <FlameSteelEngineGameToolkit/Data/Components/GameMap/GameMap.h>

using namespace FlameSteelCore;
using namespace FlameSteelEngine::GameToolkit;

class IntersectionController {

public:
	static shared_ptr<Objects> rayFromObjectIntersectsObjects(shared_ptr<Object> object, shared_ptr<ObjectsMap> objectsMap, shared_ptr<GameMap> gameMap);

};

#endif