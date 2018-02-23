/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSModelLoaderObj.h
 * Author: demensdeum
 *
 * Created on July 9, 2017, 10:07 AM
 */

#ifndef FSMODELLOADEROBJ_H
#define FSMODELLOADEROBJ_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../FSGLModelLoader.h"

#include <assimp/scene.h>
#include "../../Vertex/FSGLVertex.h"

#include <memory>

using namespace std;

class FSGLModelLoaderAssimp: public FSGLModelLoader {
public:
    FSGLModelLoaderAssimp();
    FSGLModelLoaderAssimp(const FSGLModelLoaderAssimp& orig);
    virtual ~FSGLModelLoaderAssimp();
    
    static shared_ptr<FSGLModel> loadModel(shared_ptr<string> modelPath);   
    
private:
    
    static shared_ptr<FSGLNode> convertNode(aiNode *node, shared_ptr<FSGLNode> parentNode, shared_ptr<FSGLModel> model);
    
};

#endif /* FSMODELLOADEROBJ_H */

