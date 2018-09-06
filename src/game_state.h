#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SDL2pp/SDL2pp.hh>
#include "assets.h"
#include "client.h"
class Client;
class Input;
class GameState {
public:
        GameState(
            const std::unique_ptr<SDL2pp::Renderer> & renderer,
            const std::unique_ptr<AssetsManager> & assetsManager
        );
        
        std::shared_ptr<Client> mClient;
        const std::unique_ptr<SDL2pp::Renderer> & renderer;
        const std::unique_ptr<AssetsManager> & assetsManager;
        
        void HandleInput(const std::shared_ptr<Input> & input);
        void Update();
        void Shoot();
        
    private:
        std::map<std::string, std::shared_ptr<Client>> clients;
};

#endif // GAMESTATE_H
