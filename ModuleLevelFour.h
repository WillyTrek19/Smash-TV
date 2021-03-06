#ifndef __MODULE_LEVEL_FOUR_H
#define __MODULE_LEVEL_FOUR_H

#include "Module.h"
#include "SDL/include/SDL.h"
#include "Particle.h"

struct SDL_Texture;

class ModuleLevelFour : public Module {
public:
    //Constructor
    ModuleLevelFour(bool startEnabled);
    //Destructor
    ~ModuleLevelFour();
    // Called when the module is activated
    // Loads the necessary textures for the map background
    bool Start() override;
    // Called while updating
    // Detects if the intro has ended
    UPDATE_STATUS Update() override;

    // Called at the end of the application loop.
    // Performs the render call of all the parts of the scene's background
    UPDATE_STATUS PostUpdate() override;

    bool CleanUp() override;

    bool CheckIfStarted() const;
    void SetIfStarted(bool _hasStarted);
    SDL_Rect GetBackgroundAdapter() const;

private:
    bool once = true;
    bool hasStarted = false;
    Particle* p2;
    // The sprite section for the background
    //SDL_Rect background;
    SDL_Rect backgroundAdapter;
    // The scene sprite sheet loaded into an SDL_Texture
    SDL_Texture* backgroundTexture = nullptr;

    char levelTitle[10] = { "\0" };
    char stageText[10] = { "\0" };
    char highScore[15] = { "\0" };
};

#endif