/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEOGLModel.h
 * Author: demensdeum
 *
 * Created on July 8, 2017, 10:39 AM
 */

#ifndef FSEOGLMODEL_H
#define FSEOGLMODEL_H

#include <memory>

#include "../Resource/FSGLResource.h"
#include "../Material/FSGLMaterial.h"
#include "../Mesh/FSGLMesh.h"
#include "../Serializable/FSGLSerializable.h"
#include "../Animation/FSGLAnimation.h"
#include "../Node/FSGLNode.h"

#if MSVC

#include <GL/glew.h>

#else

#include <GLES3/gl3.h>

#endif

#include <vector>

using namespace std;

class FSGLModel: public FSGLResource, public FSGLSerializable {
    
public:
    FSGLModel();
    FSGLModel(const FSGLModel& orig);
    virtual ~FSGLModel();
  
    shared_ptr<string> path;
    
    vector< shared_ptr<FSGLAnimation> > animations;
    vector< shared_ptr<FSGLMesh> > meshes;  
    shared_ptr<FSGLNode> rootNode;
    
    virtual shared_ptr<string> serializeIntoString();
    virtual shared_ptr<FSGLSerializable> deserializeFromString(shared_ptr<string> serializedData);     
    
    void applyAnimation(shared_ptr<string> animationName, double animationOffset);
    void incrementAnimation();
    
    shared_ptr<FSGLAnimation> currentAnimation;    
    
    shared_ptr<FSGLBone> findBone(shared_ptr<string> boneName);
    
	void resetTransformationMatrix();

private:
    

    
};

#endif /* FSEOGLMODEL_H */

