#include <iostream>
#include <memory>

#include <DeathMask/src/Controllers/GameController/DMGameController.h>
#include <DeathMask/src/Const/DMConstStates.h>

using namespace std;

int main()
{
	//cout << "Death Mask - Cyber Fantasy Adventure in Endless Techno-Maze\nPrepare to die!\n" << endl;

#ifdef __EMSCRIPTEN__
try
{
#endif
        auto controller = make_shared<DMGameController>();
        controller->startGameFromState(DMStateCompanyLogo);
#ifdef __EMSCRIPTEN__
}
catch (const std::exception &exc)
{
	//cout << exc.what();
}
#endif

}