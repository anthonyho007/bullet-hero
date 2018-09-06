#include "object.h"

Object::Object(
            const std::unique_ptr<SDL2pp::Renderer> & renderer,
            const std::unique_ptr<AssetsManager> & assetsManager,
            const std::string textureId,
            SDL2pp::Point position,
            SDL2pp::Point speed,
            int ratio
        ) :     renderer(renderer),
                assetsManager(assetsManager),
                textureId(textureId),
                pos(position),
                speed(speed),
                ratio(ratio)
{}

const std::shared_ptr<SDL2pp::Texture> & Object::GetTexture() const
{
    return assetsManager->GetTexture(textureId);
}

SDL2pp::Point Object::GetSize() const 
{
    return GetTexture()->GetSize() / ratio;
}

SDL2pp::Rect Object::GetRect() const
{
    return SDL2pp::Rect(pos, GetSize());
}

