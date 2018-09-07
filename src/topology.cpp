#include "topology.h"
#include "json.hpp"

using json = nlohmann::json;


Topology::Topology(
    const std::shared_ptr<GameState> &gameState
) : gameState(gameState)
{
        GetTopologyData();
}

Topology::~Topology()
{
}

void Topology::CreateTile(SDL2pp::Point pos, SDL2pp::Point size)
{
    auto tile = std::make_shared<Tile>(gameState,"blackTile", pos, size);
    tiles.push_back(tile);
}

void Topology::Update()
{
    for(auto& tile : tiles) {
        tile->Update();
    }
}

void Topology::GetTopologyData()
{
    std::ifstream topo("assets/img/topology.json");
    json jobj(topo);

    for (auto& field : jobj) {
        SDL2pp::Rect coord = CordToRect(field.find("coord"));
        CreateTile(SDL2pp::Point{coord.GetX(), coord.GetY()},
            SDL2pp::Point{coord.w, coord.h});
    }
}

