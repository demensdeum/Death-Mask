/*
 * FSEGTColliderDelegate.h
 *
 *  Created on: Sep 11, 2016
 *      Author: demensdeum
 */

#ifndef PHYSICS_FSEGTCOLLIDERDELEGATE_H_
#define PHYSICS_FSEGTCOLLIDERDELEGATE_H_

#include <memory>
#include <FlameSteelCore/FSCObject.h>

using namespace std;

class FSEGTColliderDelegate {
public:
	FSEGTColliderDelegate();

	virtual void colliderCollidesObjectWithObject(shared_ptr<FSCObject> object, shared_ptr<FSCObject> objectToCollide);

	virtual ~FSEGTColliderDelegate();
};

#endif /* PHYSICS_FSEGTCOLLIDERDELEGATE_H_ */
