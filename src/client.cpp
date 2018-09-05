#include "client.h"
Client::Client(
            const std::shared_ptr<GameState> & gameState,
            const std::string id,
            const std::string textureId,
            SDL2pp::Point pos
) : Object(
        id,
        gameState->renderer,
        gameState->assetsManager,
        textureId,
        pos,
        SDL2pp::Point{0, 0},
        0.0,
        1
    ),
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


