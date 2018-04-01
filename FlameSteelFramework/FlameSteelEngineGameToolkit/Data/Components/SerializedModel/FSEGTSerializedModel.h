#ifndef FSEGTSERIALIZEDMODELDEFINED
#define FSEGTSERIALIZEDMODELDEFINED

#include <FlameSteelCore/FSCObject.h>

class FSEGTSerializedModel: public FSCObject {

public:

	FSEGTSerializedModel(shared_ptr<string> serializedModel);

	shared_ptr<string> serializedModel;

};

#endif