
#ifndef INPUT_H
#define INPUT_H

#include "SDL2/SDL.h"

class Input
{
public:
    Input();
    const uint8_t *keystate;
    bool IsPressed(int key);
};

#endif // INPUT_H
