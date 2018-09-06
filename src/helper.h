#ifndef HELPER_H
#define HELPER_H
#include <memory>
#include <SDL2pp/SDL2pp.hh>
#include "assets.h"


template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

#endif // HELPER_H