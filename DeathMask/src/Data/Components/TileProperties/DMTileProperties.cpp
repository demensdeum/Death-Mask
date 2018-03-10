#include "DMTileProperties.h"
#include <DeathMask/src/Const/DMConstTypes.h>

#include <memory>

using namespace std;

DMTileProperties::DMTileProperties() {

	isFree = false;

	setClassIdentifier(make_shared<string>(DMConstTypesTileProperties));

};