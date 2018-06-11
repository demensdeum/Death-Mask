#ifndef DEATHMASKGAMEINGAMEUSERINTERFACECONTROLLERDEFINED
#define DEATHMASKGAMEINGAMEUSERINTERFACECONTROLLERDEFINED

#include <memory>
#include <FlameSteelEngineGameToolkit/Data/Components/Text/FSEGTText.h>
#include <DeathMask/src/Data/Components/GameplayProperties/DMGameplayProperties.h>

using namespace std;

namespace DeathMaskGame {

class InGameUserInterfaceController {

public:
	InGameUserInterfaceController(shared_ptr<FSEGTText> text, shared_ptr<DMGameplayProperties> gameplayProperties);
	void step();

private:
	shared_ptr<FSEGTText> text;
	shared_ptr<DMGameplayProperties> gameplayProperties;

};
};

#endif