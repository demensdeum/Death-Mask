/*
 * FSEGTWalkStepsComponent.h
 *
 *  Created on: Sep 14, 2016
 *      Author: demensdeum
 */

#ifndef DATA_COMPONENTS_WALKSTEPS_FSEGTWALKSTEPSCOMPONENT_H_
#define DATA_COMPONENTS_WALKSTEPS_FSEGTWALKSTEPSCOMPONENT_H_

#include <FlameSteelEngineGameToolkit/Data/Components/Vector/FSEGTVector.h>
#include <FlameSteelCore/FSCObject.h>
#include <vector>
#include <memory>

class FSEGTWalkStepsComponent: public FSCObject {
public:
	FSEGTWalkStepsComponent();

	shared_ptr<FSEGTVector> lastWalkStep();

	void addLastWalkStep(shared_ptr<FSEGTVector> walkStep);
	void removeLastWalkStep();

	virtual ~FSEGTWalkStepsComponent();

private:
	vector<shared_ptr<FSEGTVector> > steps;

};

#endif /* DATA_COMPONENTS_WALKSTEPS_FSEGTWALKSTEPSCOMPONENT_H_ */
