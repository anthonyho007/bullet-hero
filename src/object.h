#ifndef OBJECT_H
#define OBJECT_H

#include <SDL2pp/SDL2pp.hh>
#include <memory>
#include "vector2.h"
#include "assets.h"
class Object {
    public:
        const std::string id;
        SDL2pp::Point pos;
        SDL2pp::Point speed;
        float angle;

        Object(
            const std::string id,
            const std::unique_ptr<SDL2pp::Renderer> & renderer,
            const std::unique_ptr<AssetsManager> & assetsManager,
            const std::string textureId,
            SDL2pp::Point position,
            SDL2pp::Point speed,
            float angle,
            int ratio
        );
        
        const std::shared_ptr<SDL2pp::Texture> & GetTexture() const;
        SDL2pp::Rect GetRect() const;
        SDL2pp::Point GetSize() const;

    protected:
        const std::unique_ptr<SDL2pp::Renderer> & renderer;
        const std::unique_ptr<AssetsManager> & assetsManager;
        const std::string textureId;
        float ratio;

        virtual void Update() {};
};
#endif // OBJECT_H
