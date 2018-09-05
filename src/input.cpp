#include "input.h"
#include "SDL2/SDL.h"

InputManager::InputManager() {
  keys = SDL_GetKeyboardState(nullptr);
}
