#ifndef BULLET_H
#define BULLET_H

#include "screen.h"
#include "object.h"
#include "game_state.h"
#include "collision.h"
class GameState;
class Collision;
class Bullet : public std::enable_shared_from_this<Bullet>, public Object
{
public:
    Bullet(
        std::string textureId,
        const std::shared_ptr<Object> & shooter,
        const std::shared_ptr<GameState> & gameState,
        const std::shared_ptr<Collision> & collisionManager,
        int speedMul
    );
    const std::shared_ptr<Collision> & collisionManager;
    
    bool IsCollided();
    
    void Update();
private:
    int speedMultiplier;
};

#endif // BULLET_H
