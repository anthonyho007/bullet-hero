#include <iostream>
#include <SDL.h>
#include "game.h"

/*
 * Lesson 0: Test to make sure SDL is setup properly
 */
int main(int, char**){
	try {
		auto game = make_unique<Game>();
		game->Run();
	} catch (SDL2pp::Exception &e) {
		std::cerr << e.GetSDLFunction() << std::endl;
		std::cerr << e.GetSDLError() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
