#include "FSEGTVector.h"

#include <FlameSteelEngineGameToolkit/Const/FSEGTConst.h>
#include <math.h>

int FSEGTVector::getTileX() {
	int tileX = this->x / FSEGTGameMapTileSize;
	return tileX;
}

int FSEGTVector::getTileY() {
	int tileY = this->y / FSEGTGameMapTileSize;
	return tileY;
}

void FSEGTVector::rotate(float diff) {
    
    float oldX = this->x;
		
    this->x = this->x * cos(-diff) - this->y * sin(-diff);
    this->y = oldX * sin(-diff) + this->y * cos(-diff);
}

shared_ptr<FSEGTVector> FSEGTVector::vectorXYZ(float x, float y, float z) {

	shared_ptr<FSEGTVector> vector(new FSEGTVector);

	vector->x = x;
	vector->y = y;
	vector->z = z;

	return vector;
}

shared_ptr<FSCObject> FSEGTVector::copy() {
	shared_ptr<FSEGTVector> copiedVector(new FSEGTVector);

	copiedVector->x = this->x;
	copiedVector->y = this->y;
	copiedVector->z = this->z;

	copiedVector->setInstanceIdentifier(this->getInstanceIdentifier());
	copiedVector->setClassIdentifier(this->getClassIdentifier());

	return copiedVector;
}
