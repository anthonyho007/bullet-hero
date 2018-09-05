#include "assets.h"

void AssetsManager::AddSurface(std::string key, std::string path) {
    surfaces[key] = std::make_shared<SDL2pp::Surface>(SDL2pp::Surface(path));
}

const std::shared_ptr<SDL2pp::Surface> & AssetsManager::GetSurface(std::string key) const {
    return surfaces.at(key);
}

void AssetsManager::AddTexture(std::string key, SDL2pp::Texture texture) {
    AddTexture(key, std::make_shared<SDL2pp::Texture>(std::move(texture)));
}

void AssetsManager::AddTexture(std::string key, std::shared_ptr<SDL2pp::Texture> texture) {
    textures[key] = std::move(texture);
}

const std::shared_ptr<SDL2pp::Texture> & AssetsManager::GetTexture(std::string key) const {
    return textures.at(key);
}

bool AssetsManager::HasTexture(std::string key) const {
    return textures.count(key) > 0;
}

void AssetsManager::AddSheet(std::string key, SDL2pp::Texture texture) {
    AddSheet(key, std::make_shared<SDL2pp::Texture>(std::move(texture)));
}

void AssetsManager::AddSheet(std::string key, std::shared_ptr<SDL2pp::Texture> texture) {
    sheets[key] = std::move(texture);
}

const std::shared_ptr<SDL2pp::Texture> & AssetsManager::GetSheet(std::string key) const {
    return sheets.at(key);
}
