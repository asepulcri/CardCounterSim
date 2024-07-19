#include <SDL2/SDL.h>
#include <iostream>

int main() {
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Error" << SDL_GetError();
    }
    else{
        std::cout << "Hello, World!" << std::endl;
    }
    return 0;
}
