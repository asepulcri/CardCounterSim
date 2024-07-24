#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include "card.h"
#include "game.h"

game *ccs = nullptr;

int main(int argc, char* argv[]) {
    
    ccs = new game();

    ccs->init("Card Counter Simulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while(ccs->running()){
        ccs->handleEvents();
        ccs->update();
        ccs->render();
    }

    ccs->clean();

    return 0;
}