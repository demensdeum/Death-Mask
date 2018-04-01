#include "FSEGTSerializedModel.h"
#include <FlameSteelEngineGameToolkit/Const/FSEGTConst.h>

FSEGTSerializedModel::FSEGTSerializedModel(shared_ptr<string> serializedModel) {

		setClassIdentifier(make_shared<string>(FSEGTConstComponentsSerializedModel));

		this->serializedModel = serializedModel;

}