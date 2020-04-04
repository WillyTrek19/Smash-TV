#ifndef __MODULE_LEVEL_ONE_H
#define __MODULE_LEVEL_ONE_H

#include "Module.h"

struct SDL_Texture;

class ModuleLevelOne : public Module {
public:
	//Constructor
	ModuleLevelOne();
	//Destructor
	~ModuleLevelOne();
	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;
	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	UPDATE_STATUS PostUpdate();

public:

	// The scene sprite sheet loaded into an SDL_Texture
	SDL_Texture* backgroundTexture = nullptr;
	// The sprite section for the background
	SDL_Rect background;
};

#endif