#include <SDL2/SDL.h>
#include <iostream>
#include "include/card.h"

int main() {
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Error" << SDL_GetError();
    }
    else{
        SDL_Window* window = SDL_CreateWindow("Testing Window", 0, 0, 800, 600, SDL_WINDOW_SHOWN);
        SDL_Delay(1000);
        SDL_DestroyWindow(window);
    }

    SDL_Quit();

    card testCard(rank::ace, suit::clubs);

    shoe testShoe(int(3));

    testShoe.shuffleShoe();

    return 0;
}