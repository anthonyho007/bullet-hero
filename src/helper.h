#ifndef HELPER_H
#define HELPER_H
#include <memory>
#include <SDL2pp/SDL2pp.hh>
#include "assets.h"
#include "json.hpp"

using json = nlohmann::json;


template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

SDL2pp::Rect CordToRect(json::iterator coord);

void LoadAssets(
    const std::unique_ptr<SDL2pp::Renderer> & renderer,
    const std::unique_ptr<AssetsManager> & assetsManager);

#endif // HELPER_H