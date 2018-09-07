#include "client.h"

Client::Client(
            const std::shared_ptr<GameState> & gameState,
            const std::string id,
            const std::string textureId,
            SDL2pp::Point pos
) : Object(
        gameState->renderer,
        gameState->assetsManager,
        textureId,
        pos,
        SDL2pp::Point{5, 0},
        1),
    gameState(gameState),
    health(10),
    id(id),
    previousPos(pos)
{}

void Client::Update() {
    bool isCollidedWithTile = gameState->collisionManager->CheckPlayerTileCollision();
    if (isCollidedWithTile) {
        pos = previousPos;
    }
    renderer->Copy(
        *assetsManager->GetTexture(textureId),
        SDL2pp::Rect{0,0, GetRect().w, GetRect().h},
        pos,
        0,
        SDL2pp::NullOpt, 0
    );
}

void Client::HandleInput(const std::shared_ptr<Input> & input) {
    if (input->IsPressed(SDL_SCANCODE_SPACE)) {
        Fire();
    }
    previousPos = pos;
    if (input->IsPressed(SDL_SCANCODE_UP) || input->IsPressed(SDL_SCANCODE_W) || input->IsPressed(SDL_SCANCODE_K)) {
      pos.y--;
    }

    if (input->IsPressed(SDL_SCANCODE_DOWN) || input->IsPressed(SDL_SCANCODE_S) || input->IsPressed(SDL_SCANCODE_J)) {
      pos.y++;
    }

    if (input->IsPressed(SDL_SCANCODE_LEFT) || input->IsPressed(SDL_SCANCODE_A) || input->IsPressed(SDL_SCANCODE_H)) {
      pos.x--;
    }

    if (input->IsPressed(SDL_SCANCODE_RIGHT) || input->IsPressed(SDL_SCANCODE_D) || input->IsPressed(SDL_SCANCODE_L)) {
      pos.x++;
    }
}

void Client::Fire() {
    Uint32 curr = SDL_GetTicks();
    if ((curr - lastFireTime) > fireDelay) {
        CreateBullet();
        lastFireTime = curr;
    }
}

void Client::CreateBullet() {
    gameState->CreateBullet(shared_from_this());
}

bool Client::IsDead() {
    return dead;
}
