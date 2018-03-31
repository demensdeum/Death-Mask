#ifndef FSEGTSERIALIZEDMODEL
#define FSEGTSERIALZEDMODEL

#include <FlameSteelCore/FSCObject.h>
#include <DeathMask/src/Const/DMConstTypes.h>

class FSEGTSerializedModel: public FSCObject {

public:

	FSEGTSerializedModel(shared_ptr<string> serializedModel);

	shared_ptr<string> serializedModel;

};

#endif