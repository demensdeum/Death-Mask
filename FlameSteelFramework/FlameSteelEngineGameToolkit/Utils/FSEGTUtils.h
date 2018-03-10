/*
 * FSEGTUtils.h
 *
 *  Created on: Sep 11, 2016
 *      Author: demensdeum
 */

#ifndef UTILS_FSEGTUTILS_H_
#define UTILS_FSEGTUTILS_H_

#include <FlameSteelCore/FSCObject.h>
#include <FlameSteelEngineGameToolkit/Data/Components/Vector/FSEGTVector.h>
#include <string.h>

class FSEGTSerializedModel;

class FSEGTUtils: public FSCObject {
public:
	FSEGTUtils();
        
        static int getFramesCount(shared_ptr<FSCObject> object);
        static int getCurrentFrame(shared_ptr<FSCObject> object);
        static void updateObjectAnimationTick(shared_ptr<FSCObject> object);

	static void setAttackActionComponentForObject(shared_ptr<FSCObject> object);
	static void setSpeedForObject(int speed, shared_ptr<FSCObject> object);

        static shared_ptr<FSEGTVector> getObjectPosition(shared_ptr<FSCObject> object);
        static shared_ptr<FSEGTVector> getObjectScale(shared_ptr<FSCObject> object);
        static shared_ptr<FSEGTVector> getObjectRotation(shared_ptr<FSCObject> object);
        
	static void hideObject(shared_ptr<FSCObject> object);
	static void unhideObject(shared_ptr<FSCObject> object);

	static void moveObject(shared_ptr<FSCObject> object);
	static void movePositionVectorByRotationAndSpeed(shared_ptr<FSCObject> positionComponent, shared_ptr<FSCObject> eulerComponent, shared_ptr<FSCObject> speedComponent);;

        static shared_ptr<string> getText(shared_ptr<FSCObject> object);
        static void setText(shared_ptr<string> text, shared_ptr<FSCObject> object);
        static shared_ptr<string> getFont(shared_ptr<FSCObject> object);

        static shared_ptr<string> getSpritePath(shared_ptr<FSCObject> object);        
        static shared_ptr<string> getModelFilePathForObject(shared_ptr<FSCObject> object);

        static shared_ptr<string> platformPath(const char *relativePath);
        
	static shared_ptr<FSEGTSerializedModel> getSerializedModel(shared_ptr<FSCObject> object);

	virtual ~FSEGTUtils();
};

#endif /* UTILS_FSEGTUTILS_H_ */
