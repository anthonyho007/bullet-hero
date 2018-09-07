#ifndef COLLISION_H
#define COLLISION_H

#include "game_state.h"
#include "bullet.h"
class GameState;
class Bullet;
class Collision
{
public:
    Collision(const std::shared_ptr<GameState> & gameState);
    ~Collision();

    bool CheckPlayerTileCollision();
    bool UpdatePlayerBulletCollision(std::string id);
    bool CheckBulletTileCollision(const std::shared_ptr<Bullet> & bullet);
    bool IsRectIntersect(SDL2pp::Rect rect1, SDL2pp::Rect rect2);

private:
    const std::shared_ptr<GameState> & gameState;
};

#endif // COLLISION_H
