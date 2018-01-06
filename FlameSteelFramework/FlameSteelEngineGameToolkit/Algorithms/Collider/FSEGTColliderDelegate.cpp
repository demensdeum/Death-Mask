/*
 * FSEGTColliderDelegate.cpp
 *
 *  Created on: Sep 11, 2016
 *      Author: demensdeum
 */

#include <stdlib.h>
#include "FSEGTColliderDelegate.h"

FSEGTColliderDelegate::FSEGTColliderDelegate() {
	// TODO Auto-generated constructor stub

}

void FSEGTColliderDelegate::colliderCollidesObjectWithObject(shared_ptr<FSCObject> , shared_ptr<FSCObject> ) {
	printf("You need to override delegate method for FSEGTColliderDelegate");
	abort();
}

FSEGTColliderDelegate::~FSEGTColliderDelegate() {
	// TODO Auto-generated destructor stub
}