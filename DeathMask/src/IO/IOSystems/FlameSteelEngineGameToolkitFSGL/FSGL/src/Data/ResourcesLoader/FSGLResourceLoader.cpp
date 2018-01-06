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

#include "FSGLResourceLoader.h"
#include "../ModelLoader/ModelLoaderObj/FSGLModelLoaderObj.h"

FSGLResourceLoader::FSGLResourceLoader() {
}

FSGLResourceLoader::FSGLResourceLoader(const FSGLResourceLoader& ) {
}

shared_ptr<FSGLResource> FSGLResourceLoader::loadResource(shared_ptr<string> resourcePath) {
    
    if (resourcePath->find(".obj") != string::npos) {
        
        return FSGLModelLoaderObj::loadModel(resourcePath);
    }
    
    return shared_ptr<FSGLResource>();
}

FSGLResourceLoader::~FSGLResourceLoader() {
}
