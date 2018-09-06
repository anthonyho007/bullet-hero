/*
#ifndef SRC_ClIENT_H_
#define SRC_ClIENT_H_

#include <spdlog/spdlog.h>
#include <memory>
#include <vector>
#include "actor.h"
#include "bullet.h"
#include "input.h"
#include "assets.h"

class LevelStage;

typedef struct ClientStats {
  int health = 100;
  int health_max = 100;
  int level = 1;
} ClientStats;

class Client : public Actor, public std::enable_shared_from_this<Client> {
 public:
  Client(const std::shared_ptr<LevelStage>& stage,
       const std::string& texture_key,
       SDL2pp::Point position,
       SDL2pp::Point velocity = {0, 0},
       const std::shared_ptr<ClientStats>& stats = std::make_shared<ClientStats>(),
       int flip = 0);

  void Update() final;
  void OnHitByBullet(std::shared_ptr<Bullet> bullet);
  int GetFlip() const { return flip; }
  void SetHit(bool h) { hit = h; }
  void SpawnBullet(void);
  std::shared_ptr<ClientStats> stats;
  std::vector<std::shared_ptr<Bullet>> bullets;
  const std::shared_ptr<LevelStage>& stage;
  const std::shared_ptr<spdlog::logger>& console;
};

class PlayerClient : public Client {
 public:
  PlayerClient(
      const std::shared_ptr<LevelStage>& stage,
      const std::string& texture_key,
      SDL2pp::Point position,
      SDL2pp::Point velocity = {0, 0},
      const std::shared_ptr<ClientStats>& stats = std::make_shared<ClientStats>(),
      int flip = 0);
  void HandleInput(const std::shared_ptr<InputManager>& input);
};

class Player {
 public:
  Player(const std::shared_ptr<LevelStage>& stage);

  void HandleInput(const std::shared_ptr<InputManager>& input);
  std::shared_ptr<PlayerClient> Client;
};
#endif  // SRC_ClIENT_H_

*/
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
