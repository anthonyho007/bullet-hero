#ifndef CLIENT_H
#define CLIENT_H

#include "object.h"
#include "constant.h"
#include "game_state.h"
#include "input.h"

class GameState;
class Client : public Object, public std::enable_shared_from_this<Client> {
    public:
        Client(
            const std::shared_ptr<GameState> &gameState,
            const std::string id,
            const std::string textureId,
            SDL2pp::Point pos
        );
        void Update();
        void HandleInput(const std::shared_ptr<Input> & input);

        void Fire();
        

    private:
        int heath;
};
#endif // CLIENT_H
