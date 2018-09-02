#include <iostream>
#include <memory>

#include <DeathMask/src/Controllers/GameController/DMGameController.h>
#include <DeathMask/src/Const/DMConstStates.h>

using namespace std;

int main()
{
	cout << "Death Mask - Cyber Fantasy Adventure in Endless Techno-Maze\nPrepare to die!\n" << endl;

try {
        auto controller = make_shared<DMGameController>();
        controller->startGameFromState(DMStateCompanyLogo);
} catch(...) {
    cout << "Caught something else" << endl;
	auto expPtr = std::current_exception();

try {

            std::rethrow_exception(expPtr);

    } catch(const std::exception& e) {
        std::cout << "Caught exception \"" << e.what() << "\"\n";
    }

  }
}