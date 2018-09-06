#include "game.h"
#include "json.hpp"

using json = nlohmann::json;

SDL2pp::Rect CordToRect(json::iterator coord) {
  std::array<int, 4> arr;
  int ctr = 0;
  for (json::iterator i = coord->begin(); i != coord->end(); ++i) {
    arr[ctr] = i->get<int>();
    ctr+=1;
  }
  return SDL2pp::Rect{arr[0], arr[1], arr[2], arr[3]};
}

void LoadAssets(
const std::unique_ptr<SDL2pp::Renderer> & renderer,
const std::unique_ptr<AssetsManager> & assetsManager) 
{
    std::ifstream img("assets/img/spritesheet.json");
    json jobj(img);
    
    for (auto & field : jobj) {
        assetsManager->AddSurface(field.find("name").value(), field.find("location").value());
        std::string key = field.find("name").value();
        assetsManager->AddSheet(
            key,
            SDL2pp::Texture(*renderer,
                            *assetsManager->GetSurface(key))
        );
    }
    std::ifstream s ("assets/img/sprite.json");
    json jobj2(s);
    for (auto &field : jobj2) {
        std::string name = field.find("name").value();
        std::string sheet = field.find("sheet").value();
        SDL2pp::Rect coord = CordToRect(field.find("coord"));
        if (!assetsManager->HasTexture(name)) {
            auto sprite = std::make_shared<SDL2pp::Texture>(
                *renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET,
                coord.w, coord.h);
            sprite->SetBlendMode(SDL_BLENDMODE_BLEND);
            renderer->SetTarget(*sprite);
            renderer->Clear();
            renderer->SetDrawBlendMode(SDL_BLENDMODE_BLEND);
            renderer->Copy(
                *assetsManager->GetSheet(sheet),
                coord,
                SDL2pp::NullOpt
            );
            assetsManager->AddTexture(name, sprite);
            renderer->SetTarget();
        }
    }
}

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
        assetsManager(make_unique<AssetsManager>()),
        input(std::make_shared<Input>()),
        sdl_renderer(make_unique<SDL2pp::Renderer>(
          sdl_window,
          -1,
          SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE))
{
    LoadAssets(sdl_renderer, assetsManager);
    gamestate = std::make_shared<GameState>(sdl_renderer, assetsManager);
    gamestate->mClient = std::make_shared<Client>(gamestate, "player1", "player1",SDL2pp::Point{30, 30});
    
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

