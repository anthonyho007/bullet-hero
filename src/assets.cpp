#include "assets.h"

void AssetsManager::AddTexture(std::string key, SDL2pp::Texture texture) {
    AddTexture(key, std::make_shared<SDL2pp::Texture>(std::move(texture)));
}

void AssetsManager::AddTexture(std::string key, std::shared_ptr<SDL2pp::Texture> texture) {
    texture[key] = std::move(texture);
}

const std::shared_ptr<SDL2pp::Texture> & GetTexture(std::string key) {
    return textures.at(key);
}

bool HasTexture(std::string key) const {
    return textures.count(key) > 0
}