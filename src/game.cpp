#include "game.h"

Game::Game()
    :   sdl(SDL_INIT_VIDEO),
        sdl_image(IMG_INIT_PNG),
        sdl_window(
            "Bullet Hero",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            Screen.w,
            Screen.h,
            SDL_WINDOW_RESIZABLE
        ),
        sdl_renderer(make_unique<SDL2pp::Renderer>(
          sdl_window,
          -1,
          SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE)),
        assetsManager(make_unique<AssetsManager>()),
        input(std::make_shared<Input>())
{
    LoadAssets(sdl_renderer, assetsManager);
    gamestate = std::make_shared<GameState>(sdl_renderer, assetsManager);
    gamestate->mClient = std::make_shared<Client>(gamestate, "player1", "player1",SDL2pp::Point{30, 30});
    gamestate->topologyManger = std::make_shared<Topology>(gamestate);
}

void Game::Run() {
    SDL_Event evt = {};
    while (!quit) {
        if (SDL_PollEvent(&evt)) {
            PollEvent(&evt);
        }
        sdl_renderer->SetDrawColor(255, 255, 255, 255);
        sdl_renderer->Clear();
        sdl_renderer->SetViewport(Screen);
        gamestate->HandleInput(input);
        gamestate->Update();
        
        sdl_renderer->Present();
        SDL_Delay(5);
    }
}

void Game::PollEvent(const SDL_Event *evt)
{
    switch(evt->type) {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_KEYDOWN:
            switch(evt->key.keysym.sym) {
                case SDLK_ESCAPE: case SDLK_q:
                quit = true;
                break;
            }
            break;
    }
}

