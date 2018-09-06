#include <SDL2pp/SDL2pp.hh>

const SDL2pp::Rect Screen = {
    0,
    0,
    640,
    480
};

const SDL2pp::Rect GAME_GRID = {
    0,
    0,
    static_cast<int>(Screen.w * 0.95),
    static_cast<int>(Screen.h * 0.95)
};