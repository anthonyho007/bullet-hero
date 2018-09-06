#include "bullet.h"

Bullet::Bullet(
    std::string textureId,
    const std::shared_ptr<Object> & shooter,
    const std::shared_ptr<GameState> & gameState,
    int speedMul
) : Object(
    gameState->renderer,
    gameState->assetsManager,
    textureId,
    SDL2pp::Point{0, 0},
    SDL2pp::Point{5, 0},
    2),
    gameState(gameState),
    speedMultiplier(speedMul)
{
    pos = SDL2pp::Point {shooter->pos.x, shooter->pos.y};
    speed = SDL2pp::Point {shooter->speed.x, shooter->speed.y};
}

bool Bullet::IsCollided() {
    return GAME_GRID.Contains(pos) ? false : true;
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
            0
        );
        pos += speed * speedMultiplier;
    }
}
