#include "input.h"

Input::Input()
{
    keystate = SDL_GetKeyboardState(nullptr);
}

bool Input::IsPressed(int key)
{
    return keystate[key];
}