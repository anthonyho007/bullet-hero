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
    // check if clients get hit by bullets
    for(auto& client : clients) {
        collisionManager->UpdatePlayerBulletCollision(client.first);

        if (client.second->health <= 0) {
            std::cout << "Player " + client.first + " is dead" << std::endl;
            // clients.erase(client.first);
            auto enemy = client.second;
            enemy->health = 10;
            enemy->pos = SDL2pp::Point{rand()%600,rand()%400};

            bool isCollidedWithTile = enemy->gameState->collisionManager->CheckPlayerTileCollision();

            while (isCollidedWithTile) {
                enemy->pos = SDL2pp::Point{rand()%600,rand()%400};
                isCollidedWithTile = enemy->gameState->collisionManager->CheckPlayerTileCollision();
            }
        }
    }
    topologyManger->Update();
    // draw client
    for (auto& client : clients) {
        client.second->Update();
    }
//    mClient->Update();
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
        collisionManager,
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

void GameState::createUser(const std::shared_ptr<GameState> & gamestate, std::string id, std::string textureId, SDL2pp::Point pos, bool isLocalPlayer) {
    auto client = std::make_shared<Client>(gamestate, id, textureId, pos);
    clients[id] = client;
    if (isLocalPlayer) {
        mClient = client;
    }
}
