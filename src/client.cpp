
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
    id(id),
    heath(5)
{}
void Client::Update() {
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
