/*
 * FSEGTComponentsGenerator.h
 *
 *  Created on: Sep 4, 2016
 *      Author: demensdeum
 */

#ifndef DATA_COMPONENTS_FSEGTCOMPONENTSGENERATOR_H_
#define DATA_COMPONENTS_FSEGTCOMPONENTSGENERATOR_H_

#include <FlameSteelCore/FSCObject.h>
#include <memory>
#include <string>

#include <FlameSteelEngineGameToolkit/Data/Components/Vector/FSEGTVector.h>
#include <FlameSteelEngineGameToolkit/Data/Components/Sprite/FSEGTSprite.h>
#include <FlameSteelEngineGameToolkit/Data/Components/ModelReference/FSEGTModelReference.h>
#include <FlameSteelEngineGameToolkit/Data/Components/Text/FSEGTText.h>

class FSEGTSerializedModel;

using namespace std;

class FSEGTFactory: public FSCObject {
public:

        // object
        
        static shared_ptr <FSCObject> makeOnSceneObject(
                                        shared_ptr<string> classIdentifier,
                                        shared_ptr<string> instanceIdentifier,
                                        shared_ptr<string> spriteFilePath,
                                        shared_ptr<string> modelFilePath,
						  shared_ptr<string> serializedModel,
                                        float x,
                                        float y,
                                        float z,
                                        float width,
                                        float height,
                                        float depth,
                                        float rotationX,
                                        float rotationY,
                                        float rotationZ,
                                        int speed                 
                                      );

        // components
        
	static shared_ptr <FSEGTVector> makePositionComponent(float x = 0, float y = 0, float z = 0);
	static shared_ptr <FSEGTVector> makeRotationComponent(float rotationX, float rotationY, float rotationZ);
        static shared_ptr <FSEGTVector> makeSpeedComponent(int speed);
	static shared_ptr <FSEGTSprite> makeSpriteComponent(shared_ptr<string> spriteFilePath);
        static shared_ptr <FSEGTText>   makeTextComponent(shared_ptr<string> fontResourceIdentifier, shared_ptr<string> text);
        static shared_ptr <FSEGTModelReference>  makeModelReferenceComponent(shared_ptr<string> modelFilePath);
        static shared_ptr <FSEGTVector> makeScaleComponent(float width, float height, float depth);
	static shared_ptr<FSEGTSerializedModel> makeSerializedModelComponent(shared_ptr<string> serializedModel);
};

#endif /* DATA_COMPONENTS_FSEGTCOMPONENTSGENERATOR_H_ */
