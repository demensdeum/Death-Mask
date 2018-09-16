#ifndef DEATHMASKGAMEINGAMEUSERINTERFACECONTROLLERDEFINED
#define DEATHMASKGAMEINGAMEUSERINTERFACECONTROLLERDEFINED

#include <memory>
#include <DeathMask/src/Data/Components/GameplayProperties/DMGameplayProperties.h>

using namespace std;

namespace DeathMaskGame {

class InGameUserInterfaceController;

class InGameUserInterfaceControllerDataSource {

public:
	virtual shared_ptr<Objects> objectsForInGameUserInterfaceController(shared_ptr<InGameUserInterfaceController> inGameUserInterfaceController);

};

class InGameUserInterfaceController: public enable_shared_from_this<InGameUserInterfaceController> {

public:
	InGameUserInterfaceController(shared_ptr<Object> camera,
											shared_ptr<DMGameplayProperties> gameplayProperties, 
												shared_ptr<InGameUserInterfaceControllerDataSource> dataSource);
	void step();
	shared_ptr<Object> uiObject;

private:
	shared_ptr<Object> camera;
	shared_ptr<DMGameplayProperties> gameplayProperties;
	shared_ptr<InGameUserInterfaceControllerDataSource> dataSource;
};
};

#endif