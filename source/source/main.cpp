#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include "Card.h"
#include "Game.h"

Game *ccs = nullptr;

int main(int argc, char* argv[]) {

    // Run at 60 Hz
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;
    
    // Initialise new game
    ccs = new Game();

    ccs->init("Card Counter Simulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while(ccs->running()){

        frameStart = SDL_GetTicks();

        ccs->handleEvents();
        ccs->update();
        ccs->render();

        frameTime = SDL_GetTicks() - frameStart;

        // Make sure we're running at desired FPS
        if(frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    ccs->clean();

    return 0;
}