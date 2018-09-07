#include "bullet.h"

Bullet::Bullet(
    std::string textureId,
    const std::shared_ptr<Object> & shooter,
    const std::shared_ptr<GameState> & gameState,
    const std::shared_ptr<Collision> & collisionManager,
    int speedMul
) : Object(
    gameState->renderer,
    gameState->assetsManager,
    textureId,
    SDL2pp::Point{0, 0},
    SDL2pp::Point{5, 0},
    2),
    collisionManager(collisionManager),
    speedMultiplier(speedMul)
{
    pos = SDL2pp::Point {shooter->pos.x + shooter->GetSize().x, shooter->pos.y + shooter->GetSize().y};
    speed = SDL2pp::Point {shooter->speed.x, shooter->speed.y};
}

bool Bullet::IsCollided() {
    bool isCollided = collisionManager->CheckBulletTileCollision(shared_from_this());
    return isCollided;
}

void Bullet::Update() {
    if(!IsCollided()) {
        renderer->Copy(
            *assetsManager->GetTexture(textureId),
            SDL2pp::NullOpt,
            SDL2pp::Rect(
                pos,
                assetsManager->GetTexture(textureId)->GetSize() * ratio
            ),
            15
        );
        pos += speed * speedMultiplier;
    }
}
