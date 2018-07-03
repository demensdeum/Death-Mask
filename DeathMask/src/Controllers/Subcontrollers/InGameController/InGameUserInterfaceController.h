#ifndef DEATHMASKGAMEINGAMEUSERINTERFACECONTROLLERDEFINED
#define DEATHMASKGAMEINGAMEUSERINTERFACECONTROLLERDEFINED

#include <memory>
#include <FlameSteelEngineGameToolkit/Data/Components/Text/FSEGTText.h>
#include <DeathMask/src/Data/Components/GameplayProperties/DMGameplayProperties.h>

using namespace std;

namespace DeathMaskGame {

class InGameUserInterfaceController;

class InGameUserInterfaceControllerDataSource {

public:
	virtual shared_ptr<FSCObjects> objectsForInGameUserInterfaceController(shared_ptr<InGameUserInterfaceController> inGameUserInterfaceController);

};

class InGameUserInterfaceController: public enable_shared_from_this<InGameUserInterfaceController> {

public:
	InGameUserInterfaceController(shared_ptr<FSEGTText> text, 
											shared_ptr<DMGameplayProperties> gameplayProperties, 
												shared_ptr<InGameUserInterfaceControllerDataSource> dataSource);
	void step();

private:
	shared_ptr<FSEGTText> text;
	shared_ptr<DMGameplayProperties> gameplayProperties;
	shared_ptr<InGameUserInterfaceControllerDataSource> dataSource;
};
};

#endif