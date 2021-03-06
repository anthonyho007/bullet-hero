#include "collision.h"

Collision::Collision(const std::shared_ptr<GameState> & gameState)
    : gameState(gameState)
{}

bool Collision::CheckPlayerTileCollision() {
    auto client = gameState->mClient;
    for(auto& tile : gameState->topologyManger->tiles) {
        if (IsRectIntersect(client->GetRect(), tile->GetRect())) {
            return true;
        }
    }
    return false;
}

bool Collision::CheckBulletTileCollision(const std::shared_ptr<Bullet> &bullet) {
    for (auto& tile : gameState->topologyManger->tiles) {
        if (IsRectIntersect(tile->GetRect(), bullet->GetRect())) {
            return true;
        }
    }
    return false;
}

bool Collision::UpdatePlayerBulletCollision(std::string id) {
    auto client = gameState->clients[id];
    
    auto iter = std::begin(gameState->bullets);
    while (iter != std::end(gameState->bullets)) {
        auto bullet = *iter;
        if (IsRectIntersect(client->GetRect(), bullet->GetRect())) {
            iter = gameState->bullets.erase(iter);
            client->health--;
        }else {
            ++iter;
        }
    }
}

bool Collision::IsRectIntersect(SDL2pp::Rect rect1, SDL2pp::Rect rect2)
{
    return rect1.Intersects(rect2);
}

Collision::~Collision()
{
}