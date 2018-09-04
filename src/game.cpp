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
          SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE)) {
}

void Game::Run() {
    SDL_Event evt = {};
    while (!quit) {
        if (SDL_PollEvent(&evt)) {
            PollEvent(&evt);
        }
        sdl_renderer->SetDrawColor(220, 220, 220, 255);
        sdl_renderer->Clear();
        sdl_renderer->SetViewport(Screen);

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

