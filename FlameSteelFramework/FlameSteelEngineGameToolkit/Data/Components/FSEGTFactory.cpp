/*
 * FSEGTComponentsGenerator.cpp
 *
 *  Created on: Sep 4, 2016
 *      Author: demensdeum
 */

#include <FlameSteelEngineGameToolkit/Const/FSEGTConst.h>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <FlameSteelEngineGameToolkit/Data/Components/Sprite/FSEGTSprite.h>
#include <FlameSteelEngineGameToolkit/Data/Components/SerializedModel/FSEGTSerializedModel.h>

shared_ptr <FSEGTModelReference> FSEGTFactory::makeModelReferenceComponent(shared_ptr<string> modelFilePath) {


    auto component = make_shared<FSEGTModelReference>(modelFilePath);

    component->setClassIdentifier(make_shared<string>(FSEGTConstComponentsModel));
    component->setInstanceIdentifier(make_shared<string>(FSEGTConstComponentsModel));

    return component;
}

shared_ptr <FSCObject> FSEGTFactory::makeOnSceneObject(
        shared_ptr<string> classIdentifier,
        shared_ptr<string> instanceIdentifier,
        shared_ptr<string> spriteFilePath,
        shared_ptr<string> modelFilePath,
	  shared_ptr<string> serializedModel,
        float x, float y, float z,
        float width, float height, float depth,
        float rotationX, float rotationY, float rotationZ,
        int speed
        ) {
    
    auto onSceneObject = make_shared<FSCObject>();

    onSceneObject->setClassIdentifier(classIdentifier);
    onSceneObject->setInstanceIdentifier(instanceIdentifier);

    if (spriteFilePath.get() != nullptr) {

        auto spriteComponent = FSEGTFactory::makeSpriteComponent(spriteFilePath);

        spriteComponent->width = width;
        spriteComponent->height = height;

        onSceneObject->addComponent(spriteComponent);

    }
    
    if (modelFilePath.get() != nullptr) {
        
        auto modelComponent = FSEGTFactory::makeModelReferenceComponent(modelFilePath);
        
        onSceneObject->addComponent(modelComponent);
    }

   if (serializedModel.get() != nullptr) {

		auto serializedModelComponent = FSEGTFactory::makeSerializedModelComponent(serializedModel);
	    onSceneObject->addComponent(serializedModelComponent);

	}

    onSceneObject->addComponent(FSEGTFactory::makePositionComponent(x, y, z));
    onSceneObject->addComponent(FSEGTFactory::makeScaleComponent(width, height, depth));
    onSceneObject->addComponent(FSEGTFactory::makeSpeedComponent(speed));
    onSceneObject->addComponent(FSEGTFactory::makeRotationComponent(rotationX, rotationY, rotationZ));

    return onSceneObject;
}

shared_ptr<FSEGTSerializedModel> FSEGTFactory::makeSerializedModelComponent(shared_ptr<string> serializedModel) {

	auto serializedModelComponent = make_shared<FSEGTSerializedModel>(serializedModel);
	
	return serializedModelComponent;
}

shared_ptr <FSEGTText> FSEGTFactory::makeTextComponent(shared_ptr<string> fontResourceIdentifier, shared_ptr<string> text) {

    auto textComponent = make_shared<FSEGTText>();
    textComponent->setInstanceIdentifier(make_shared<string>(FSEGTConstComponentsText));
    textComponent->setClassIdentifier(make_shared<string>(FSEGTConstComponentsText));

    textComponent->fontResourceIdentifier = fontResourceIdentifier;
    textComponent->text = text;

    return textComponent;
}

shared_ptr <FSEGTVector> FSEGTFactory::makeScaleComponent(float width, float height, float depth) {
    
    auto scaleComponent = make_shared<FSEGTVector>();
    scaleComponent->setInstanceIdentifier(make_shared<string>(FSEGTConstComponentsScale));
    scaleComponent->setClassIdentifier(make_shared<string>(FSEGTConstComponentsScale));

    scaleComponent->x = width;
    scaleComponent->y = height;
    scaleComponent->z = depth;
    
    return scaleComponent;
}

shared_ptr <FSEGTVector> FSEGTFactory::makePositionComponent(float x, float y, float z) {
    
    auto positionComponent = make_shared<FSEGTVector>();
    positionComponent->setInstanceIdentifier(make_shared<string>(FSEGTConstComponentsPosition));
    positionComponent->setClassIdentifier(make_shared<string>(FSEGTConstComponentsPosition));

    positionComponent->x = x;
    positionComponent->y = y;
    positionComponent->z = z;

    return positionComponent;
}

shared_ptr <FSEGTVector> FSEGTFactory::makeRotationComponent(float rotationX, float rotationY, float rotationZ) {
    
    auto component = make_shared<FSEGTVector>();
    component->setInstanceIdentifier(make_shared<string>(FSEGTConstComponentsRotation));
    component->setClassIdentifier(make_shared<string>(FSEGTConstComponentsRotation));

    component->x = rotationX;
    component->y = rotationY;
    component->z = rotationZ;

    return component;
}

shared_ptr <FSEGTVector> FSEGTFactory::makeSpeedComponent(int speed) {
    auto component = make_shared<FSEGTVector>();

    component->setInstanceIdentifier(make_shared<string>(FSEGTConstComponentsSpeed));
    component->setClassIdentifier(make_shared<string>(FSEGTConstComponentsSpeed));

    component->x = speed;

    return component;

}

shared_ptr <FSEGTSprite> FSEGTFactory::makeSpriteComponent(shared_ptr<string> spriteFilePath) {

    shared_ptr <FSEGTSprite> sprite(new FSEGTSprite(spriteFilePath));
    sprite->setInstanceIdentifier(make_shared<string>(FSEGTConstComponentsSprite));
    sprite->setClassIdentifier(make_shared<string>(FSEGTConstComponentsSprite));

    return sprite;
}
