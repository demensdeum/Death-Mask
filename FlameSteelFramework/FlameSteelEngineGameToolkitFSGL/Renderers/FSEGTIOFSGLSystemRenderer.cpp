/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTIOFSGLSystemRenderer.cpp
 * Author: demensdeum
 * 
 * Created on August 5, 2017, 6:45 PM
 */

#include "FSEGTIOFSGLSystemRenderer.h"

#include <iostream>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>

#include "../Data/FSGTIOFSGLSystemFactory.h"

FSEGTIOFSGLSystemRenderer::FSEGTIOFSGLSystemRenderer() {
}

FSEGTIOFSGLSystemRenderer::FSEGTIOFSGLSystemRenderer(const FSEGTIOFSGLSystemRenderer& ) {
}

void FSEGTIOFSGLSystemRenderer::initialize() {

    controller = make_shared<FSGLController>();
    controller->initialize();

}

void FSEGTIOFSGLSystemRenderer::render(shared_ptr<FSEGTGameData> ) {

    controller->render();

}

void FSEGTIOFSGLSystemRenderer::objectsContextObjectAdded(shared_ptr<FSEGTObjectsContext> , shared_ptr<FSCObject> object) {

    //cout << "FSEGTIOFSGLSystemRenderer: object add - " << object->getInstanceIdentifier()->c_str() << endl;

	if (object->getClassIdentifier().get() == nullptr) {

		cout << "FSEGTIOFSGLSystemRenderer: empty name for added object - exit" << endl;

		exit(1);
	
	}

    if (object->getClassIdentifier()->compare("scene object") == 0) {

        auto graphicsObject = FSGTIOFSGLSystemFactory::graphicsObjectFrom(object);

        controller->addObject(graphicsObject);

    } else if (object->getClassIdentifier()->compare("ui") == 0) {

    } else if (object->getClassIdentifier()->compare("camera") == 0) {

        auto position = FSEGTUtils::getObjectPosition(object);
        auto rotation = FSEGTUtils::getObjectRotation(object);

        controller->setCameraX(position->x);
        controller->setCameraY(position->y);
        controller->setCameraZ(position->z);

        controller->setCameraRotationX(rotation->x);
        controller->setCameraRotationY(rotation->y);
        controller->setCameraRotationZ(rotation->z);

    }
}

void FSEGTIOFSGLSystemRenderer::objectsContextObjectUpdate(shared_ptr<FSEGTObjectsContext> , shared_ptr<FSCObject> object) {

    if (object->getClassIdentifier()->compare("scene object") == 0) {

        auto position = FSEGTUtils::getObjectPosition(object);
        auto rotation = FSEGTUtils::getObjectRotation(object);
        
        auto id = object->id;
        auto graphicsObject = controller->getObjectWithID(id);
        
        graphicsObject->positionVector->x = position->x;
        graphicsObject->positionVector->y = position->z;
        graphicsObject->positionVector->z = position->y;
        
        graphicsObject->rotationVector->x = rotation->x;
        graphicsObject->rotationVector->y = rotation->y;
        graphicsObject->rotationVector->z = rotation->z;

    } else if (object->getClassIdentifier()->compare("camera") == 0) {

        auto position = FSEGTUtils::getObjectPosition(object);
        auto rotation = FSEGTUtils::getObjectRotation(object);

        controller->setCameraX(position->x);
        controller->setCameraY(position->y);
        controller->setCameraZ(position->z);

        controller->setCameraRotationX(rotation->x);
        controller->setCameraRotationY(rotation->y);
        controller->setCameraRotationZ(rotation->z);

    }

}

void FSEGTIOFSGLSystemRenderer::addRenderID(int id) {
    
    controller->addRenderID(id);
    
}

void FSEGTIOFSGLSystemRenderer::cleanRenderIDs() {
    
    controller->cleanRenderIDs();
    
}

void FSEGTIOFSGLSystemRenderer::objectsContextAllObjectsRemoved(shared_ptr<FSEGTObjectsContext> ) {

    //cout << "FSEGTIOFSGLSystemRenderer: all objects removed" << endl;

    controller->removeAllObjects();
    
}

FSEGTIOFSGLSystemRenderer::~FSEGTIOFSGLSystemRenderer() {
}