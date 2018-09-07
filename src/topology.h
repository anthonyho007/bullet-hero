#ifndef TOPOLOGY_H
#define TOPOLOGY_H

#include "helper.h"
#include "tile.h"

class Tile;
class Topology
{
public:
    Topology(
        const std::shared_ptr<GameState> &gameState
    );

    ~Topology();
    void GetTopologyData();
    void CreateTile(SDL2pp::Point pos, SDL2pp::Point size);
    void Update();
    std::vector<std::shared_ptr<Tile>> tiles;
private:
    const std::shared_ptr<GameState> gameState;
};

#endif // TOPOLOGY_H
