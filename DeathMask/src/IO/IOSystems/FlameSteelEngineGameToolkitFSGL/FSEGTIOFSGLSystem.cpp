/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTIOFSGLSystem.cpp
 * Author: demensdeum
 * 
 * Created on August 5, 2017, 6:25 PM
 */

#include "FSEGTIOFSGLSystem.h"

#include <iostream>

#include "Renderers/FSEGTIOFSGLSystemRenderer.h"

#include <FlameSteelEngineGameToolkit/IO/Input/FSEGTInputController.h>

#include "Input/FSEGTIOFSGLInputController.h"

FSEGTIOFSGLSystem::FSEGTIOFSGLSystem() {
}

void FSEGTIOFSGLSystem::initialize(shared_ptr<FSEGTIOSystemParams> ) {
    
    cout << "FSGL Desktop Initialize" << endl;
    
    renderer = make_shared<FSEGTIOFSGLSystemRenderer>();
    renderer->initialize();
    
    inputController = make_shared<FSEGTIOFSGLInputController>();
}

void FSEGTIOFSGLSystem::objectsContextObjectAdded(shared_ptr<FSEGTObjectsContext> context, shared_ptr<FSCObject> object) {

    renderer->objectsContextObjectAdded(context, object);

}

void FSEGTIOFSGLSystem::objectsContextObjectUpdate(shared_ptr<FSEGTObjectsContext> context, shared_ptr<FSCObject> object) {
    
    renderer->objectsContextObjectUpdate(context, object);
    
}

void FSEGTIOFSGLSystem::objectsContextAllObjectsRemoved(shared_ptr<FSEGTObjectsContext> context) {
    
    renderer->objectsContextAllObjectsRemoved(context);
}

FSEGTIOFSGLSystem::FSEGTIOFSGLSystem(const FSEGTIOFSGLSystem& ) {
}

FSEGTIOFSGLSystem::~FSEGTIOFSGLSystem() {
}