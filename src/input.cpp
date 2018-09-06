/*
#include "input.h"
#include "SDL2/SDL.h"

InputManager::InputManager() {
  keys = SDL_GetKeyboardState(nullptr);
}
*/
#include "input.h"

Input::Input()
{
    keystate = SDL_GetKeyboardState(nullptr);
}

bool Input::IsPressed(int key)
{
    return keystate[key];
}
