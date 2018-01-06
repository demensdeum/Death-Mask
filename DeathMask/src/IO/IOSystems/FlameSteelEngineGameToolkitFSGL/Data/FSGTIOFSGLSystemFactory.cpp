/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGTIOFSGLSystemFactory.cpp
 * Author: demensdeum
 * 
 * Created on August 5, 2017, 7:28 PM
 */

#include "FSGTIOFSGLSystemFactory.h"

#include "../FSGL/src/Data/ResourcesLoader/FSGLResourceLoader.h"

#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>

#include <sstream>

FSGTIOFSGLSystemFactory::FSGTIOFSGLSystemFactory() {
}

FSGTIOFSGLSystemFactory::FSGTIOFSGLSystemFactory(const FSGTIOFSGLSystemFactory& ) {
}

shared_ptr<FSGLObject> FSGTIOFSGLSystemFactory::graphicsObjectFrom(shared_ptr<FSCObject> object) {
    
    stringstream stream;
    
    auto modelFilePath = FSEGTUtils::getModelFilePathForObject(object);
    
    stream << modelFilePath->c_str() << string(".obj");
    
    auto preparedModelFilePath = FSEGTUtils::platformPath(stream.str().c_str());
    
    auto model = static_pointer_cast<FSGLModel>(FSGLResourceLoader::loadResource(preparedModelFilePath));
    
    auto graphicsObject = make_shared<FSGLObject>(model);
    
    auto position = FSEGTUtils::getObjectPosition(object);
    
    graphicsObject->id = object->id;
    
    graphicsObject->positionVector->x = position->x;
    graphicsObject->positionVector->y = position->z;
    graphicsObject->positionVector->z = position->y;
    
    auto scale = FSEGTUtils::getObjectScale(object);
    
    graphicsObject->scaleVector->x = scale->x;
    graphicsObject->scaleVector->y = scale->y;
    graphicsObject->scaleVector->z = scale->z;
    
    return graphicsObject;
}

FSGTIOFSGLSystemFactory::~FSGTIOFSGLSystemFactory() {
}
