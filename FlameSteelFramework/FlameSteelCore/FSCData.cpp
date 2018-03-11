#include "FSCData.h"

FSCData::FSCData() {

	size = 0;
	data = nullptr;

};

shared_ptr<FSCData> FSCData::fromFilePath(shared_ptr<string> filePath) {

	auto data = make_shared<FSCData>();

	char *buffer = nullptr;
	auto file = fopen (filePath->c_str(), "rb");

	if (file != nullptr) {

		fseek (file, 0, SEEK_END);

		auto length = ftell (file);
		data->size = length;

		fseek (file, 0, SEEK_SET);
		buffer = (char *) malloc (length);

		if (buffer)
		{
			fread (buffer, 1, length, file);
		}

		data->data = buffer;

		fclose (file);
	}

	return data;
};