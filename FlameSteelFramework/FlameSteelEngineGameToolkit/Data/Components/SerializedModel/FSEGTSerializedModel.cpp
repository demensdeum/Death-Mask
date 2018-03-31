#include "FSEGTSerializedModel.h"

FSEGTSerializedModel::FSEGTSerializedModel(shared_ptr<string> serializedModel) {

		setClassIdentifier(make_shared<string>(DMConstTypesSerializedModel));

		this->serializedModel = serializedModel;

}