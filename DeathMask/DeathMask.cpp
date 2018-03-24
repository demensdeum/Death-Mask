#include <iostream>
#include <memory>

#include <DeathMask/src/Controllers/GameController/DMGameController.h>
#include <DeathMask/src/Const/DMConstStates.h>

using namespace std;

int main()
{
	cout << "Death Mask - Cyber Fantasy Adventure in Endless Techno-Maze" << endl;
        
        auto controller = make_shared<DMGameController>();
        controller->startGameFromState(DMStateInGame);        
}