#include "Game.h"
#include "TextureManager.h"

SDL_Texture *aceOfSpades;
SDL_Rect srcR, destR;

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;

    if(fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        renderer = SDL_CreateRenderer(window, -1, 0);

        if(renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

        isRunning = true;
    }

    else {
        isRunning = false;
    }

    aceOfSpades = TextureManager::LoadTexture("../assets/Ace_of_spades.png", renderer);

}

void Game::handleEvents() {
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

void Game::update() {
    destR.h = 186;
    destR.w = 128;
}

void Game::render() {
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, aceOfSpades, NULL, &destR);
    
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}