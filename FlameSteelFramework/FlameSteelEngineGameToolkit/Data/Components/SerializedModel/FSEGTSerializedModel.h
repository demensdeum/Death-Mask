#ifndef FSEGTSERIALIZEDMODEL
#define FSEGTSERIALZEDMODEL

#include <FlameSteelCore/FSCObject.h>

class FSEGTSerializedModel: public FSCObject {

public:

	shared_ptr<string> serializedModel;

};

#endif