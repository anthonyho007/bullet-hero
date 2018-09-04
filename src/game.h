#include <SDL2pp/SDL2pp.hh>
#include <SDL2/SDL_image.h>

#include "screen.h"
#include "helper.h"

class Game {
    public:
        explicit Game();
        void Run();
        void PollEvent(const SDL_Event *evt);

    private:
        SDL2pp::SDL sdl;
        SDL2pp::SDLImage sdl_image;
        SDL2pp::Window sdl_window;
        std::unique_ptr<SDL2pp::Renderer> sdl_renderer;

        bool quit = false;

};