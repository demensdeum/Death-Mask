#ifndef DEATHMASK_INTERSECTION_CONTROLLER_H_
#define DEATHMASK_INTERSECTION_CONTROLLER_H_

class IntersectionController {

public:
	vector<Objects> rayFromObjectIntersectsObjects(shared_ptr<Object> object, shared_ptr<ObjectsMap> objectsMap);

};

#endif