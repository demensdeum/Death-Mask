/*
 * FSEGTVector.h
 *
 *  Created on: Aug 4, 2016
 *      Author: demensdeum
 */

#ifndef FSEGTVECTOR_H_
#define FSEGTVECTOR_H_

#include <FlameSteelCore/FSCObject.h>

class FSESerializable;

class FSEGTVector : public FSCObject {

public:
	float x;
	float y;
	float z;

	int getTileX();
	int getTileY();
        
        void rotate(float diff);

	virtual shared_ptr<FSCObject> copy();
	static shared_ptr<FSEGTVector> vectorXYZ(float x, float y, float z);
};

#endif /* FSEGTVECTOR_H_ */
