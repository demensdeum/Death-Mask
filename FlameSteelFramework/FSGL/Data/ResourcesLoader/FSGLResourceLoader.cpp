/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLResourceLoader.cpp
 * Author: demensdeum
 * 
 * Created on July 9, 2017, 10:16 AM
 */

#include <iostream>

#include "FSGLResourceLoader.h"
#include "../ModelLoader/ModelLoaderAssimp/FSGLModelLoaderAssimp.h"
#include "../ModelLoader/ModelLoaderFSGL/FSGLModelLoaderFSGL.h"
#include <FlameSteelEngineGameToolkit/Data/Components/SerializedModel/FSEGTSerializedModel.h>

#include "../../Utils/FSGLUtils.h"

FSGLResourceLoader::FSGLResourceLoader() {
}

FSGLResourceLoader::FSGLResourceLoader(const FSGLResourceLoader& ) {
}

shared_ptr<FSGLModel> FSGLResourceLoader::deserializeModel(shared_ptr<FSEGTSerializedModel> serializedModel) {

	auto model = make_shared<FSGLModel>()->deserializeFromString(serializedModel->serializedModel);

	return static_pointer_cast<FSGLModel>(model);

}

shared_ptr<FSGLResource> FSGLResourceLoader::loadResource(shared_ptr<string> resourcePath) {
    
    cout << "FSGLResourceLoader: " << resourcePath->c_str() << endl;
    
    shared_ptr<string> extension = FSGLUtils::filePathExtension(resourcePath);
    
    if (extension->compare("obj") == 0) {
        
        return FSGLModelLoaderAssimp::loadModel(resourcePath);
        
    }
    else if (extension->compare("gltf") == 0) {
        
        return FSGLModelLoaderAssimp::loadModel(resourcePath);
        
    }
    else if (extension->compare("fbx") == 0) {
        
        return FSGLModelLoaderAssimp::loadModel(resourcePath);
        
    }
	else if (extension->compare("fsglmodel") == 0) {

		return FSGLModelLoaderFSGL::loadModel(resourcePath);

	}
    else {
        
        cout << "FSGLResourceLoader: Could not load file: " << resourcePath->c_str() << endl;
        cout << "FSGLResourceLoader: Unknown file format: " << extension->c_str() << endl;
        
    }
    
    return shared_ptr<FSGLResource>();
}

FSGLResourceLoader::~FSGLResourceLoader() {
}
