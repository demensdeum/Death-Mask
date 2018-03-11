#include <string>
#include <memory>

using namespace std;

class FSCData {

	public:
		FSCData();
		static shared_ptr<FSCData> fromFilePath(shared_ptr<string> filePath);

		size_t size;
		char *data;
};