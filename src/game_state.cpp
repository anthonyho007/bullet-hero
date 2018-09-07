#include "game_state.h"

class HandleInput;
GameState::GameState(
    const std::unique_ptr<SDL2pp::Renderer> & renderer,
    const std::unique_ptr<AssetsManager> & assetsManager)
    :   renderer(renderer),
        assetsManager(assetsManager)
{    
}


void GameState::Update() {
    topologyManger->Update();
    // draw client
    mClient->Update();
    // update and draw bullet
    RemoveInvalidBullet();
    for (auto& bullet : bullets) {
        bullet->Update();
    }
}


void GameState::HandleInput(const std::shared_ptr<Input> & input) {
    mClient->HandleInput(input);
}

void GameState::CreateBullet(const std::shared_ptr<Client> & client) {
    auto bullet = std::make_shared<Bullet>(
        "bullet1",
        client,
        shared_from_this(),
        1);
    bullets.push_back(bullet);
}

void GameState::RemoveInvalidBullet() {
    auto iter = std::begin(bullets);
    while (iter != std::end(bullets)) {
        auto bullet = *iter;
        if (bullet->IsCollided()) {
            iter = bullets.erase(iter);
        }else {
            ++iter;
        }
    }
}