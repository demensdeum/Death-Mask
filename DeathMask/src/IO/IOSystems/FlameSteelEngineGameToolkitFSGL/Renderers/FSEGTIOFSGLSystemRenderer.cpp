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

#include "../Data/FSGTIOFSGLSystemFactory.h"

FSEGTIOFSGLSystemRenderer::FSEGTIOFSGLSystemRenderer() {
}

FSEGTIOFSGLSystemRenderer::FSEGTIOFSGLSystemRenderer(const FSEGTIOFSGLSystemRenderer& orig) {
}

void FSEGTIOFSGLSystemRenderer::initialize() {
    
    controller = make_shared<FSGLController>();
    controller->initialize();
    
}

void FSEGTIOFSGLSystemRenderer::render(shared_ptr<FSEGTGameData> gameData) {
    
    controller->setCameraY(-4);
    controller->setCameraZ(-4);
    
    //controller->setCameraZ(0.1);
    
    controller->render();
    
}

void FSEGTIOFSGLSystemRenderer::objectsContextObjectAdded(shared_ptr<FSEGTObjectsContext> context, shared_ptr<FSCObject> object) {
    
    cout << "FSEGTIOFSGLSystemRenderer: object add - " << object->getInstanceIdentifier()->c_str() << endl;
    
    if (object->getClassIdentifier()->compare("scene object") == 0) {
        
        auto graphicsObject = FSGTIOFSGLSystemFactory::graphicsObjectFrom(object);
        
        controller->addObject(graphicsObject);
    
    }
    else if (object->getClassIdentifier()->compare("ui") == 0) {
        
    }
    else if (object->getClassIdentifier()->compare("camera") == 0) {
        
    }
}

void FSEGTIOFSGLSystemRenderer::objectsContextObjectUpdate(shared_ptr<FSEGTObjectsContext> context, shared_ptr<FSCObject> object) {
    
    //cout << "FSEGTIOFSGLSystemRenderer: object update - " << object->getInstanceIdentifier()->c_str() << endl;
    
}

void FSEGTIOFSGLSystemRenderer::objectsContextAllObjectsRemoved(shared_ptr<FSEGTObjectsContext> context) {
    
    cout << "FSEGTIOFSGLSystemRenderer: all objects removed" << endl;
    
}

FSEGTIOFSGLSystemRenderer::~FSEGTIOFSGLSystemRenderer() {
}

