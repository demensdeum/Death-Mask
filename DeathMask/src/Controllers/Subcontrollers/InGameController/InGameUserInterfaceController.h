#ifndef DEATHMASKGAMEINGAMEUSERINTERFACECONTROLLERDEFINED
#define DEATHMASKGAMEINGAMEUSERINTERFACECONTROLLERDEFINED

#include <SDL2/SDL.h>
#ifdef __EMSCRIPTEN__
#include <SDL_ttf.h>
#else
#include <SDL2/SDL_ttf.h>
#endif
#include <memory>
#include <DeathMask/src/Data/Components/GameplayProperties/DMGameplayProperties.h>

using namespace std;

namespace FlameSteelEngine {
namespace GameToolkit {
	class SurfaceMaterial;
};
};

using namespace FlameSteelEngine::GameToolkit;

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

	virtual ~InGameUserInterfaceController();

private:
	shared_ptr<SurfaceMaterial> surfaceMaterial;
	shared_ptr<Object> camera;
	shared_ptr<DMGameplayProperties> gameplayProperties;
	shared_ptr<InGameUserInterfaceControllerDataSource> dataSource;

	TTF_Font *font = nullptr;
	string previousRenderedString;
};
};

#endif