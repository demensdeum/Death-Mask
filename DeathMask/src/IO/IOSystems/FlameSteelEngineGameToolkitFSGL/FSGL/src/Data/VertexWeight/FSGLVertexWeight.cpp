/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLVertexWeight.cpp
 * Author: demensdeum
 * 
 * Created on November 5, 2017, 1:31 PM
 */

#include "FSGLVertexWeight.h"

FSGLVertexWeight::FSGLVertexWeight() {
}

FSGLVertexWeight::FSGLVertexWeight(const FSGLVertexWeight& ) {
}

FSGLVertexWeight::~FSGLVertexWeight() {
}

void FSGLVertexWeight::applyTransformationMatrix(shared_ptr<FSGLMatrix> transformationMatrix) {

	vertex->applyTransformationMatrixWithWeight(transformationMatrix, weight);

}

shared_ptr<FSGLMatrix> FSGLVertexWeight::transformationMatrix() {

	auto transformationMatrix = bone->transformationMatrix();

	// apply transformation by weight

	return transformationMatrix;
}