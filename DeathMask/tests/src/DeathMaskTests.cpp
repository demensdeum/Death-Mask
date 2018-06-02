#include "ObjectsGeneratorTest.h"
#include "TestsPerformer.h"
#include <memory>

using namespace std;
using namespace DeathMaskGame::Tests;
 
int main() {

	auto testsPerformer = make_shared<TestsPerformer>();
	testsPerformer->perform();

	return 0;

}