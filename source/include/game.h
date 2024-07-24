#ifndef game_h
#define game_h

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>

class game {
    public:
        game();
        ~game();

        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

        void handleEvents();
        void update();
        void render();
        void clean();

        bool running() {return isRunning;};

    private:
        int counter = 0;

        bool isRunning;
        SDL_Window *window;
        SDL_Renderer *renderer;
};

#endif