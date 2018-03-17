/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEOGLModel.cpp
 * Author: demensdeum
 * 
 * Created on July 8, 2017, 10:39 AM
 */

#include "FSGLModel.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <regex>

#include "../ResourcesLoader/FSGLResourceLoader.h"

using namespace std;

FSGLModel::FSGLModel() {
    
}
   
shared_ptr<string> FSGLModel::serializeIntoString() {
    
    stringstream serializedData;

	serializedData << "Flame Steel Graphics Library Model @ Demens Deum" << endl;
	serializedData << "Model version = Happy Sasquatch (1.0)"<< endl;

	for (auto mesh : meshes) {

		serializedData << "Mesh" << endl;

		for (auto vertexObject : mesh->verticesObjects) {

			auto position = vertexObject->position;
			auto uvTextureCoordinates = vertexObject->uvTextureCoordinates;

			serializedData << "Vertex - x = " << position->x << ", y = " << position->y << ", z = " << position->z << ", u = " << uvTextureCoordinates->u << ", v = " << uvTextureCoordinates->v << endl;

		}

		for (auto index : mesh->indices) {
	
			serializedData << "Index = " << index << endl;

		}

		serializedData << "Material - Texture path = " << mesh->material->texturePath->c_str() << endl;


	}

    
    auto stringContainer = make_shared<string>(serializedData.str());    

    return stringContainer;
}

shared_ptr<FSGLSerializable> FSGLModel::deserializeFromString(shared_ptr<string> serializedData) {

    auto model = make_shared<FSGLModel>();
    
    cout << "Read serialized data:" << endl;    

std::istringstream f(serializedData->c_str());

	std::string line;

	auto mesh = shared_ptr<FSGLMesh>();

    while (std::getline(f, line)) {
       
 //std::cout << line << std::endl;

	if (line.find("Mesh") != std::string::npos) {

		mesh = make_shared<FSGLMesh>();
		model->meshes.push_back(mesh);

		cout << "Mesh was added" << endl;

	}
	else if (line.find("Vertex") != std::string::npos) {

	    std::regex r(".*x = (.*), y = (.*), z = (.*), u = (.*), v = (.*)");
	    std::smatch m;
	    std::regex_search(line, m, r);

		float x = stof(m[1].str());
		float y = stof(m[2].str());
		float z = stof(m[3].str());
		float u = stof(m[4].str());
		float v = stof(m[5].str());

		if (mesh.get() == nullptr) {

			cout << "FSGLModel deserialize from string error - mesh is null - incorrect model string format" << endl;
			exit(1);
		}

		auto vertexObject = make_shared<FSGLVertex>(x, y, z, u, v);
		mesh->verticesObjects.push_back(vertexObject);

	}
	else if (line.find("Index = ") != std::string::npos) {

	    std::regex r("Index = (.*)");
	    std::smatch m;
	    std::regex_search(line, m, r);

		if (mesh.get() == nullptr) {

			cout << "FSGLModel deserialize from string error - mesh is null - incorrect model string format" << endl;
			exit(1);
		}

		auto index = stoi(m[1].str());
		mesh->indices.push_back(index);

	}
	else if (line.find("Material - Texture path = ") != std::string::npos) {

	    std::regex r("Material - Texture path = (.*)");
	    std::smatch m;
	    std::regex_search(line, m, r);

		if (mesh.get() == nullptr) {

			cout << "FSGLModel deserialize from string error - mesh is null - incorrect model string format" << endl;
			exit(1);
		}

		auto texturePath = make_shared<string>(m[1].str());

                auto convertedMaterial = make_shared<FSGLMaterial>(texturePath);

                auto surface = SDL_LoadBMP(convertedMaterial->texturePath->c_str());

                if (surface == nullptr) {

                    cout << "FSGLModelLoaderAssimp: cannot load texture: " << convertedMaterial->texturePath->c_str() << endl;

                }

                auto surfaceLength = surface->w * surface->h * 3;

                // swap bgr -> rgb

                for (auto i = 0; i < surfaceLength; i += 3) {

                    auto pixels = (Uint8 *) surface->pixels;

                    auto blueComponent = pixels[i];
                    auto greenComponent = pixels[i + 1];
                    auto redComponent = pixels[i + 2];

                    pixels[i] = redComponent;
                    pixels[i + 1] = greenComponent;
                    pixels[i + 2] = blueComponent;

                }

                convertedMaterial->surface = surface;

		mesh->material = convertedMaterial;

            mesh->updateGlData();
	}

    }
    
    return model;
}

void FSGLModel::resetTransformationMatrix() {

    for (auto mesh : meshes) {

		mesh->resetTransformationMatrix();

	}

}

shared_ptr<FSGLBone> FSGLModel::findBone(shared_ptr<string> boneName) {
    
    for (auto mesh : meshes) {
        
        auto foundBone = mesh->findBone(boneName);
        
        if (foundBone.get() != nullptr) {
            
            return foundBone;
            
        }
        
    }
    
	cout << "Bone not found " << boneName->c_str() << endl;

    return shared_ptr<FSGLBone>();
    
}

void FSGLModel::applyAnimation(shared_ptr<string> animationName, double animationOffset) {
    
    for (auto animation : animations) {
        
        if (animation->name->compare(animationName->c_str()) == 0) {
            
            currentAnimation = animation;
            currentAnimation->setCurrentOffset(animationOffset);

		return;
        }
    }
}

FSGLModel::~FSGLModel() {

}