#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2/SDL_image.h>

#include "assets.h"
#include "client.h"
#include "helper.h"
#include "topology.h"

class GameState;
class Client;
class Input;
class Object;
class AssetsManager;
class Topology;

class Game
{
public:
    explicit Game();
    void Run();
    void PollEvent(const SDL_Event *evt);
private:
    SDL2pp::SDL sdl;
    SDL2pp::SDLImage sdl_image;
    SDL2pp::Window sdl_window;
    std::shared_ptr<GameState> gamestate;
    std::unique_ptr<SDL2pp::Renderer> sdl_renderer;
    std::unique_ptr<AssetsManager> assetsManager;
    std::shared_ptr<Input> input;

    bool quit = false;
};

#endif // GAME_H
