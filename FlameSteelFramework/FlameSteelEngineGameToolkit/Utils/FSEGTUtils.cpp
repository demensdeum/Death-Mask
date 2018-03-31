/*
 * FSEGTUtils.cpp
 *
 *  Created on: Sep 11, 2016
 *      Author: demensdeum
 */

#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>

#ifndef _WIN32

#include <unistd.h>

#endif

#include <FlameSteelEngineGameToolkit/Data/Components/Text/FSEGTText.h>

#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <FlameSteelEngineGameToolkit/Const/FSEGTConst.h>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <FlameSteelEngineGameToolkit/Data/Components/Vector/FSEGTVector.h>
#include <FlameSteelEngineGameToolkit/Data/Components/Sprite/FSEGTSprite.h>
#include <FlameSteelEngineGameToolkit/Data/Components/ModelReference/FSEGTModelReference.h>
#include <FlameSteelEngineGameToolkit/Data/Components/SerializedModel/FSEGTSerializedModel.h>

using namespace std;

FSEGTUtils::FSEGTUtils() {
    // TODO Auto-generated constructor stub

}

int FSEGTUtils::getCurrentFrame(shared_ptr<FSCObject> object) {

    auto spriteComponentSharedPointer = object->getComponent(make_shared<string>(FSEGTConstComponentsSprite));

    auto spriteComponent = (FSEGTSprite *) spriteComponentSharedPointer.get();

    if (spriteComponent == nullptr) {

        return 0;
    }

    return spriteComponent->frameIndex;
}

int FSEGTUtils::getFramesCount(shared_ptr<FSCObject> object) {

    auto spriteComponentSharedPointer = object->getComponent(make_shared<string>(FSEGTConstComponentsSprite));

    auto spriteComponent = (FSEGTSprite *) spriteComponentSharedPointer.get();

    if (spriteComponent == nullptr) {

        return 0;
    }

    return spriteComponent->framesCount;
}

shared_ptr<string> FSEGTUtils::getFont(shared_ptr<FSCObject> object) {

    auto textSharedPointer = object->getComponent(make_shared<string>(FSEGTConstComponentsText));

    auto textComponent = (FSEGTText *) textSharedPointer.get();

    auto fontResourceIdentifier = textComponent->fontResourceIdentifier;

    return fontResourceIdentifier;
}

shared_ptr<FSEGTSerializedModel> FSEGTUtils::getSerializedModel(shared_ptr<FSCObject> object) {

	    auto serializedModelComponent = object->getComponent(make_shared<string>(FSEGTConstComponentsSerializedModel));

    return static_pointer_cast<FSEGTSerializedModel>(serializedModelComponent);

}

void FSEGTUtils::updateObjectAnimationTick(shared_ptr<FSCObject> object) {

    auto spriteComponentSharedPointer = object->getComponent(make_shared<string>(FSEGTConstComponentsSprite));

    auto spriteComponent = (FSEGTSprite *) spriteComponentSharedPointer.get();

    if (spriteComponent != nullptr) {

        spriteComponent->updateAnimationTick();
    }
}

shared_ptr<string> FSEGTUtils::getModelFilePathForObject(shared_ptr<FSCObject> object) {

    auto modelComponentSharedPointer = object->getComponent(make_shared<string>(FSEGTConstComponentsModel));

    auto modelComponent = (FSEGTModelReference*) modelComponentSharedPointer.get();

    if (modelComponentSharedPointer == nullptr) {

        return shared_ptr<string>();
    }

    if (modelComponent == nullptr) {

        return shared_ptr<string>();
    }

    return modelComponent->modelFilePath;
}

shared_ptr<string> FSEGTUtils::platformPath(const char *relativePath) {

    // oh yeah, this is pain

#ifdef _WIN32
    // oh come on Microsoft, it's 2017, make this goddamn realpath function, srsly

    char absolutePath[_MAX_PATH + 1];

    _fullpath(absolutePath, relativePath, _MAX_PATH);

    const char *imagePath = absolutePath;
#else
#ifdef  __EMSCRIPTEN__

    // give path as is to emscripten

    const char *imagePath = relativePath;
#else                
    // resolve to absolutePath for other platforms, assume nix

    char currentPath[PATH_MAX + 1];

    if (getcwd(currentPath, sizeof (currentPath)) != nullptr) {

        printf("FSEGTUtils: Current path %s\n", currentPath);

    }

    char absolutePath[PATH_MAX + 1] = {0};

    char relativePathBuffer[PATH_MAX + 1] = {0};
    strncpy(relativePathBuffer, relativePath, strlen(relativePath));

    if (!realpath(relativePathBuffer, absolutePath)) {

        cout << "FSEGTUtils: Cannot resolve path \"" << relativePathBuffer << "\" to realpath: " << strerror(errno) << endl;

        exit(1);
    }

    char *imagePath = absolutePath;
#endif
#endif                    
    shared_ptr<string> platformPath(new string(imagePath));

    return platformPath;
}

shared_ptr<string> FSEGTUtils::getText(shared_ptr<FSCObject> object) {

    auto textSharedPointer = object->getComponent(make_shared<string>(FSEGTConstComponentsText));

    auto textComponent = (FSEGTText *) textSharedPointer.get();

    if (textComponent != nullptr) {

        auto text = textComponent->text;

        return text;

    }

    return shared_ptr<string>();
}

void FSEGTUtils::setText(shared_ptr<string> text, shared_ptr<FSCObject> object) {

    auto textSharedPointer = object->getComponent(make_shared<string>(FSEGTConstComponentsText));

    if (textSharedPointer.get() == nullptr) {

        object->addComponent(FSEGTFactory::makeTextComponent(shared_ptr<string>(), make_shared<string>(FSEGTConstComponentsText)));

    }

    textSharedPointer = object->getComponent(make_shared<string>(FSEGTConstComponentsText));
    
    auto textComponent = (FSEGTText *) textSharedPointer.get();
    
    textComponent->text = text;
}

shared_ptr<FSEGTVector> FSEGTUtils::getObjectPosition(shared_ptr<FSCObject> object) {

    auto positionComponent = object->getComponent(make_shared<string>(FSEGTConstComponentsPosition));

    return static_pointer_cast<FSEGTVector>(positionComponent);

}

shared_ptr<FSEGTVector> FSEGTUtils::getObjectRotation(shared_ptr<FSCObject> object) {

    auto rotationComponent = object->getComponent(make_shared<string>(FSEGTConstComponentsRotation));

    return static_pointer_cast<FSEGTVector>(rotationComponent);
}

shared_ptr<FSEGTVector> FSEGTUtils::getObjectScale(shared_ptr<FSCObject> object) {

    auto scaleComponent = object->getComponent(make_shared<string>(FSEGTConstComponentsScale));

    return static_pointer_cast<FSEGTVector>(scaleComponent);

}

void FSEGTUtils::hideObject(shared_ptr<FSCObject> object) {

    if (!object->getComponent(make_shared<string>(FSEGTConstComponentsDeleted))) {

        shared_ptr<FSCObject> deletedComponent(new FSCObject);
        deletedComponent->setInstanceIdentifier(make_shared<string>(FSEGTConstComponentsDeleted));
        deletedComponent->setClassIdentifier(make_shared<string>(FSEGTConstComponentsDeleted));
        object->addComponent(deletedComponent);
        printf("deleted component added\n");

    }
}

void FSEGTUtils::unhideObject(shared_ptr<FSCObject> object) {

    object->removeComponent(make_shared<string>(FSEGTConstComponentsDeleted));

}

void FSEGTUtils::movePositionVectorByRotationAndSpeed(shared_ptr<FSCObject> positionComponent, shared_ptr<FSCObject> eulerComponent, shared_ptr<FSCObject> speedComponent) {

    if (positionComponent && eulerComponent && speedComponent) {

        FSEGTVector *position = (FSEGTVector *) positionComponent.get();
        FSEGTVector *eulerVector = (FSEGTVector *) eulerComponent.get();
        FSEGTVector *speed = (FSEGTVector *) speedComponent.get();

        float degreeAngle = eulerVector->y;
        degreeAngle = -degreeAngle; //invert
        float radiansAngle = degreeAngle;

        float xDiff = cos(radiansAngle) * speed->x;
        float yDiff = sin(radiansAngle) * speed->x;

        position->x += xDiff;
        position->y += yDiff;

    }

}

void FSEGTUtils::moveObject(shared_ptr<FSCObject> object) {

    shared_ptr<FSCObject> positionComponent = object->getComponent(make_shared<string>(FSEGTConstComponentsPosition));
    shared_ptr<FSCObject> eulerComponent = object->getComponent(make_shared<string>(FSEGTConstComponentsRotation));
    shared_ptr<FSCObject> speedComponent = object->getComponent(make_shared<string>(FSEGTConstComponentsSpeed));

    if (positionComponent && eulerComponent && speedComponent) {

        FSEGTUtils::movePositionVectorByRotationAndSpeed(positionComponent, eulerComponent, speedComponent);
    }

}

void FSEGTUtils::setSpeedForObject(int speed, shared_ptr<FSCObject> object) {
    shared_ptr<FSCObject> speedComponent = object->getComponent(make_shared<string>(FSEGTConstComponentsSpeed));

    if (!speedComponent) {
        shared_ptr<FSEGTVector> newSpeedComponent(new FSEGTVector);
        newSpeedComponent->setInstanceIdentifier(make_shared<string>(FSEGTConstComponentsSpeed));
        newSpeedComponent->setClassIdentifier(make_shared<string>(FSEGTConstComponentsSpeed));

        object->addComponent(newSpeedComponent);

        speedComponent = newSpeedComponent;
    }

    FSEGTVector *speedVector = (FSEGTVector *) speedComponent.get();
    speedVector->x = speed;
}

void FSEGTUtils::setAttackActionComponentForObject(shared_ptr<FSCObject> ) {

}

shared_ptr<string> FSEGTUtils::getSpritePath(shared_ptr<FSCObject> object) {

    auto spriteComponentSharedPointer = object->getComponent(make_shared<string>(FSEGTConstComponentsSprite));

    auto spriteComponent = (FSEGTSprite *) spriteComponentSharedPointer.get();

    if (spriteComponent == nullptr) {

        return nullptr;
    }

    return spriteComponent->spriteFilePath;
}

FSEGTUtils::~FSEGTUtils() {
    // TODO Auto-generated destructor stub
}
