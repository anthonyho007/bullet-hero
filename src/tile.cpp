#include "tile.h"

Tile::Tile(
    const std::shared_ptr<GameState> & gameState,
    const std::string textureId,
    SDL2pp::Point pos,
    SDL2pp::Point size
) : Object (
        gameState->renderer,
        gameState->assetsManager,
        textureId,
        pos,
        size,
        1)
{}

Tile::~Tile()
{
}

SDL2pp::Point Tile::GetSize() const
{
    return speed;
}

SDL2pp::Rect Tile::GetRect() const
{
    return SDL2pp::Rect(pos, speed);
}

void Tile::Update()
{
    renderer->Copy(
        *assetsManager->GetTexture(textureId),
        SDL2pp::NullOpt,
        GetRect(),
        0
    );
}
