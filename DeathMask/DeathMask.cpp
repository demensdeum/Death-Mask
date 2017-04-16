#include <iostream>
#include <memory>

#include <DeathMask/src/Controllers/GameController/DMGameController.h>
#include <DeathMask/src/Const/DMConstStates.h>

using namespace std;

int main()
{
	cout << "Welcome to Death Mask - roguelike game in cyberpunk setting" << endl;
        
        auto controller = std::make_shared<DMGameController>();
        controller->startGameFromState(DMStateCredits);        
}