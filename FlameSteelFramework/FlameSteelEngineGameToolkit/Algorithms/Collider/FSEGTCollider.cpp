/*
 * FSEGTCollider.cpp
 *
 *  Created on: Aug 14, 2016
 *      Author: demensdeum
 */

#include "FSEGTCollider.h"
#include "FlameSteelEngineGameToolkit/Data/Components/Vector/FSEGTVector.h"
#include "FlameSteelEngineGameToolkit/Const/FSEGTConst.h"

FSEGTCollider::FSEGTCollider() {
    delegate = nullptr;
}

void FSEGTCollider::collideObjectWithOthers(shared_ptr<FSCObject> objectToCollide, shared_ptr<FSCObjects> gameObjects) {

    for (auto i = 0; i < gameObjects->size(); i++) {
        shared_ptr<FSCObject> object = gameObjects->objectAtIndex(i);
        if (object && object != objectToCollide) {

            auto componentName = make_shared<string>(FSEGTConstComponentsPosition);

            shared_ptr<FSCObject> positionComponent = object->getComponent(componentName);
            shared_ptr<FSCObject> objectToCollidePositionComponent = objectToCollide->getComponent(componentName);

            if (positionComponent && objectToCollidePositionComponent) {

                // TODO correct on templates
                FSEGTVector *position = (FSEGTVector *) positionComponent.get();
                FSEGTVector *objectToCollidePosition = (FSEGTVector *) objectToCollidePositionComponent.get();

                int objectAx = position->getTileX();
                int objectAy = position->getTileY();

                int objectBx = objectToCollidePosition->getTileX();
                int objectBy = objectToCollidePosition->getTileY();

                // collide per tile
                if (objectAx != objectBx) {
                    continue;
                }
                if (objectAy != objectBy) {
                    continue;
                }

                //				printf("objectAx: %d\nobjectBx: %d\n",objectAx, objectBx);
                //				printf("objectAy: %d\nobjectBy: %d\n",objectAy, objectBy);

                // collide!
                //TODO delegate, etc
                //				printf("collides!\n");
                if (this->getDelegate()) {
                    this->getDelegate()->colliderCollidesObjectWithObject(object, objectToCollide);
                }
            }
        }
    }
}

FSEGTColliderDelegate* FSEGTCollider::getDelegate() {
    return this->delegate;
}

void FSEGTCollider::setDelegate(FSEGTColliderDelegate *delegate) {
    this->delegate = delegate;
}

FSEGTCollider::~FSEGTCollider() {
    // TODO Auto-generated destructor stub
}
