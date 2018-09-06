#include "game_state.h"

GameState::GameState(
    const std::unique_ptr<SDL2pp::Renderer> & renderer,
    const std::unique_ptr<AssetsManager> & assetsManager)
    :   renderer(renderer),
        assetsManager(assetsManager)
{    
}


void GameState::Update() {
    mClient->Update();
}


void GameState::HandleInput(const std::shared_ptr<Input> & input) {
    mClient->HandleInput(input);
}