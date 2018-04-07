 
#include "FSGLVertex.h"

#include <iostream>
#include <string>

using namespace std;

#define VERTEX_DEBUGGING 0

FSGLVertex::FSGLVertex(float x, float y, float z, float u, float v) {

	position = make_shared<FSGLVector>(x, y, z);
	uvTextureCoordinates = make_shared<FSGLUVTextureCoordinates>(u , v);

#if VERTEX_DEBUGGING

	cout << "x = " << x << "; y = " << y << "; z = " << z << ";" << endl;  
	cout << "u = " << u << "; v = " << v << ";" << endl;  

#endif

}

void FSGLVertex::updateAnimatedPosition() {


}

void FSGLVertex::updateTransformMatrix() {

	

}

void FSGLVertex::resetTransformationMatrix() {

	cout << "resetTransformationMatrix()" << endl;

	transformMatrix = make_shared<FSGLMatrix>();

}

void FSGLVertex::applyTransformationMatrixWithWeight(shared_ptr<FSGLMatrix> transformationMatrix, float weight) {

	if (transformMatrix.get() == nullptr) {

		cout << "FSGLVertex::applyTransformationMatrixWithWeight - vertex transform matrix not installed/resetted - exit" << endl;
		
		exit(55);

	}

	cout << "FSGLVertex::applyTransformationMatrixWithWeight" << " weight: " << weight << ";" << endl;

	if (transformationMatrix.get() == nullptr)
{
	cout << "FSGLVertex::applyTransformationMatrixWithWeight - transformationMatrix = nullptr" << endl;

	exit(3);
}

	weight = weight;
	auto weightedMatrix = transformationMatrix->matrix * weight;

	this->transformMatrix->matrix *= weightedMatrix;

}