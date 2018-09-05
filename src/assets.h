#ifndef ASSETS_H
#define ASSETS_H

#include <SDL2pp/SDL2pp.hh>
#include <map>
#include <memory>
#include <fstream>

#include "json.hpp"

using json = nlohmann::json;

class AssetsManager {
    public:
        AssetsManager() {};
        void AddSurface(std::string key, std::string path);
        const std::shared_ptr<SDL2pp::Surface> & GetSurface(std::string key)const;
        
        void AddTexture(std::string key, SDL2pp::Texture texture);
        void AddTexture(std::string key, std::shared_ptr<SDL2pp::Texture> texture);
        const std::shared_ptr<SDL2pp::Texture> & GetTexture(std::string key) const;
        bool HasTexture(std::string key) const;
        
        void AddSheet(std::string key, SDL2pp::Texture texture);
        void AddSheet(std::string key, std::shared_ptr<SDL2pp::Texture> texture);
        const std::shared_ptr<SDL2pp::Texture> & GetSheet(std::string key) const;


    private:
        std::map<std::string, std::shared_ptr<SDL2pp::Texture>> textures;
        std::map<std::string, std::shared_ptr<SDL2pp::Texture>> sheets;
        std::map<std::string, std::shared_ptr<SDL2pp::Surface>> surfaces;
};
#endif // ASSETS_H
