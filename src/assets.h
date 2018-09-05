#include <SDL2pp/SDL2pp.hh>
#include <map>
#include <memory>

class AssetsManager {
    public:
        AssetsManager() {};
        void AddTexture(std::string key, SDL2pp::Texture texture);
        void AddTexture(std::string key, std::shared_ptr<SDL2pp::Texture> texture);
        const std::shared_ptr<SDL2pp::Texture> & GetTexture(std::string key) const;
        bool HasTexture(std::string key) const;

    private:
        std::map<std::string, std::shared_ptr<SDL2pp::Texture>> textures;
}