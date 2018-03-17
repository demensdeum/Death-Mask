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

#include <FSGL/Data/ResourcesLoader/FSGLResourceLoader.h>

#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <FlameSteelEngineGameToolkit/Data/Components/SerializedModel/FSEGTSerializedModel.h>

#include <sstream>

FSGTIOFSGLSystemFactory::FSGTIOFSGLSystemFactory() {
}

FSGTIOFSGLSystemFactory::FSGTIOFSGLSystemFactory(const FSGTIOFSGLSystemFactory& ) {
}

shared_ptr<FSGLObject> FSGTIOFSGLSystemFactory::graphicsObjectFrom(shared_ptr<FSCObject> object) {
    
    auto model = shared_ptr<FSGLModel>();
    
    auto modelFilePath = FSEGTUtils::getModelFilePathForObject(object);
    auto serializedModel = FSEGTUtils::getSerializedModel(object);

	if (modelFilePath.get() != nullptr) {

	    stringstream stream;
    
	    stream << modelFilePath->c_str();
    
	    auto preparedModelFilePath = FSEGTUtils::platformPath(stream.str().c_str());

	    model = static_pointer_cast<FSGLModel>(FSGLResourceLoader::loadResource(preparedModelFilePath));

	}
	else if (serializedModel.get() != nullptr) {

		model = FSGLResourceLoader::deserializeModel(serializedModel);

	}
    
	if (model.get() == nullptr) {

		return shared_ptr<FSGLObject>();

	}

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
