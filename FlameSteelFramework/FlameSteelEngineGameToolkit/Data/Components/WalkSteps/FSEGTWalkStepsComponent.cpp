/*
 * FSEGTWalkStepsComponent.cpp
 *
 *  Created on: Sep 14, 2016
 *      Author: demensdeum
 */

#include <FlameSteelEngineGameToolkit/Data/Components/WalkSteps/FSEGTWalkStepsComponent.h>

FSEGTWalkStepsComponent::FSEGTWalkStepsComponent() {
	// TODO Auto-generated constructor stub

}

void FSEGTWalkStepsComponent::addLastWalkStep(shared_ptr<FSEGTVector> walkStep) {
	this->steps.push_back(walkStep);
}

void FSEGTWalkStepsComponent::removeLastWalkStep() {
	this->steps.pop_back();
}

shared_ptr<FSEGTVector> FSEGTWalkStepsComponent::lastWalkStep() {
	return this->steps.back();
}

FSEGTWalkStepsComponent::~FSEGTWalkStepsComponent() {
	// TODO Auto-generated destructor stub
}

