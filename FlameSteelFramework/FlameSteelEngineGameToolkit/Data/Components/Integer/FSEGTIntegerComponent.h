/*
 * FSEGTIntegerComponent.h
 *
 *  Created on: Sep 10, 2016
 *      Author: demensdeum
 */

#ifndef DATA_COMPONENTS_INTEGER_FSEGTINTEGERCOMPONENT_H_
#define DATA_COMPONENTS_INTEGER_FSEGTINTEGERCOMPONENT_H_

#include <FlameSteelCore/FSCObject.h>

class FSEGTIntegerComponent: public FSCObject {
public:
	FSEGTIntegerComponent();

	int value;

	virtual ~FSEGTIntegerComponent();
};

#endif /* DATA_COMPONENTS_INTEGER_FSEGTINTEGERCOMPONENT_H_ */
