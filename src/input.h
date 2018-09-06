/*
#ifndef SRC_INPUT_H_
#define SRC_INPUT_H_
#include <cstdint>

class InputManager {
 public:
  InputManager();
  const uint8_t* keys;
  inline constexpr bool down(const int key) {
    return static_cast<bool>(keys[key]);
  }
};
#endif  // SRC_INPUT_H_
*/
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
