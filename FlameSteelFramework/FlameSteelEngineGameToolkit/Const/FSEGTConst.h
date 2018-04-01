#ifndef FSEGTConst_defined
#define FSEGTConst_defined

#include <string>
using namespace std;

#define FSEGTGameMapTileSize 64
#define FSEGTMaxSceneObjects 1024

enum
{
	FSEGTConstCeiling,
	FSEGTConstWall,
	FSEGTConstFloor
};

#define FSEGTConstTextureSize 64
#define FSEGT_MAX_TILES_COUNT 64

static const string FSEGTConstComponentsScale = "Scale";
static const string FSEGTConstComponentsPosition = "Position";
static const string FSEGTConstComponentsRotation = "Rotation";
static const string FSEGTConstComponentsEulerRotation = "Euler Rotation";
static const string FSEGTConstComponentsAI = "AI";
static const string FSEGTConstComponentsSprite = "Sprite";
static const string FSEGTConstComponentsSpeed = "Speed";
static const string FSEGTConstComponentsDeleted = "Deleted";
static const string FSEGTConstComponentsText = "Text";
static const string FSEGTConstComponentsModel = "3D Model";
static const string FSEGTConstComponentsSerializedModel = "3D Serialized Model";

#endif
