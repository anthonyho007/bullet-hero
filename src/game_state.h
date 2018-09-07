#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SDL2pp/SDL2pp.hh>
#include "assets.h"
#include "object.h"
#include "client.h"
#include "bullet.h"
#include "string.h"
#include "topology.h"
class Input;
class Bullet;
class Client;
class Topology;
class Collision;
class GameState : public std::enable_shared_from_this<GameState>{
public:
        GameState(
            const std::unique_ptr<SDL2pp::Renderer> & renderer,
            const std::unique_ptr<AssetsManager> & assetsManager
        );
        
        std::shared_ptr<Client> mClient;
        const std::unique_ptr<SDL2pp::Renderer> & renderer;
        const std::unique_ptr<AssetsManager> & assetsManager;
        std::shared_ptr<Topology> topologyManger;
        std::shared_ptr<Collision> collisionManager;
        
        void HandleInput(const std::shared_ptr<Input> & input);
        void Update();
        void Shoot();
        std::string GenNextBulletId();
        void CreateBullet(const std::shared_ptr<Client> & client);
        void RemoveInvalidBullet();
        
        
private:
    int nextBulletId = 0;
    std::map<std::string, std::shared_ptr<Client>> clients;
    std::vector<std::shared_ptr<Bullet>> bullets;
};

#endif // GAMESTATE_H
