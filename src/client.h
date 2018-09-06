#ifndef CLIENT_H
#define CLIENT_H

#include "constant.h"
#include "game_state.h"
#include "input.h"
#include "object.h"

class GameState;
class Object;
class Client : public std::enable_shared_from_this<Client>, public Object
{
    public:
        Client(
            const std::shared_ptr<GameState> &gameState,
            const std::string id,
            const std::string textureId,
            SDL2pp::Point pos
        );
        
        const std::shared_ptr<GameState> & gameState;
        void Update();
        void HandleInput(const std::shared_ptr<Input> & input);

        void Fire();
        
        void CreateBullet();

private:
    std::string id;
    int heath;
    Uint32 lastFireTime = 0;
    Uint32 fireDelay = 100;
};
#endif // CLIENT_H
