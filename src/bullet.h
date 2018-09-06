#ifndef BULLET_H
#define BULLET_H

#include "screen.h"
#include "object.h"
#include "game_state.h"
class GameState;
class Bullet : public Object
{
public:
    Bullet(
        std::string textureId,
        const std::shared_ptr<Object> & shooter,
        const std::shared_ptr<GameState> & gameState,
        int speedMul
    );
    
    const std::shared_ptr<GameState> & gameState;
    
    bool IsCollided();
    
    void Update();
private:
    int speedMultiplier;
};

#endif // BULLET_H
