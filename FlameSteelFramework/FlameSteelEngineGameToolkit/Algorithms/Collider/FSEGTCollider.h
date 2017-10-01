/*
 * FSEGTCollider.h
 *
 *  Created on: Aug 14, 2016
 *      Author: demensdeum
 */

#ifndef FSEGTCOLLIDER_H_
#define FSEGTCOLLIDER_H_

#include <memory>
#include <FlameSteelCore/FSCObject.h>
#include <FlameSteelCore/FSCObjects.h>
#include <FlameSteelEngineGameToolkit/Algorithms/Collider/FSEGTColliderDelegate.h>

using namespace std;

class FSEGTCollider: public FSCObject {
public:
	FSEGTCollider();

	void collideObjectWithOthers(shared_ptr<FSCObject> objectToCollide, shared_ptr<FSCObjects> gameObjects);

	void setDelegate(FSEGTColliderDelegate *delegate);
	FSEGTColliderDelegate *getDelegate();
	virtual ~FSEGTCollider();

private:
	FSEGTColliderDelegate *delegate;

};

#endif /* FSEGTCOLLIDER_H_ */
