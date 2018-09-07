#ifndef TILE_H
#define TILE_H
#include "object.h"
#include "game_state.h"
class GameState;
class Tile : public Object
{
public:
    Tile(
        const std::shared_ptr<GameState> & gameState,
        const std::string textureId,
        SDL2pp::Point pos,
        SDL2pp::Point size
    );
    ~Tile();
    SDL2pp::Point GetSize() const;
    SDL2pp::Rect GetRect() const;
    void Update();
private:
    const SDL2pp::Point size;
};

#endif // TILE_H
