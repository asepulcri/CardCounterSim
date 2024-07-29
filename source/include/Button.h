#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "GameObject.h"

enum ButtonSprite {
    mouseOut,
    mouseOverMotion,
    mouseDown,
    mouseUp,
    total
};

class Button {
    public:
        // Constructor and destructor
        Button(int width, int height, SDL_Renderer *ren);
        ~Button();

        // Position top left of button
        void setPosition(int x, int y);

        // Handle mouse event
        void handleEvent(SDL_Event *event);

        // Render button
        void render(int x, int y);

    private:
        // Button top left position
        SDL_Point buttonPosition;

        // Button properties
        int buttonWidth;
        int buttonHeight;
        SDL_Renderer *renderer;

        // Button sprite
        ButtonSprite currentSprite;
};