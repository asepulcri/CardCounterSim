#include "game.h"

SDL_Texture *aceOfSpades;
SDL_Rect srcR, destR;

game::game() {

}

game::~game() {

}

void game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;

    if(fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems initialised" << std::endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if(window) {
            std::cout << "Created window" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);

        if(renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Created renderer" << std::endl;
        }

        isRunning = true;
    }

    else {
        isRunning = false;
    }

    int imgFlags = IMG_INIT_JPG;

    if( !( IMG_Init( imgFlags ) && imgFlags ) ) {
        std::cout << "SDL_image could not initialize! SDL_image Error:" << IMG_GetError() << std::endl;
    }

    SDL_Surface *tmpSurface = IMG_Load("../assets/Ace_of_spades.png");

    std::cout << IMG_GetError() << std::endl;

    aceOfSpades = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    
    SDL_FreeSurface(tmpSurface);

}

void game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }

}

void game::update() {
}

void game::render() {
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, aceOfSpades, NULL, NULL);
    
    // add to renderer
    SDL_RenderPresent(renderer);
}

void game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}