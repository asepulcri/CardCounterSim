#include "Button.h"

Button::Button(int width, int height, SDL_Renderer *ren) {
    buttonWidth = width;
    buttonHeight = height;
    renderer = ren;
}

void Button::setPosition(int x, int y) {
    buttonPosition.x = x;
    buttonPosition.y = y;
}

void Button::handleEvent(SDL_Event *event) {
    if(event->type == SDL_MOUSEMOTION || event->type == SDL_MOUSEBUTTONDOWN || event->type == SDL_MOUSEBUTTONUP) {
        // Mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);

        // Check mouse is inside button
        bool inside = true;

        // Mouse is left of the button
		if(x < buttonPosition.x) {
			inside = false;
		}

		// Mouse is right of the button
		else if(x > buttonPosition.x + buttonWidth) {
			inside = false;
		}
        
		// Mouse above the button
		else if(y < buttonPosition.y) {
			inside = false;
		}

		// Mouse below the button
		else if(y > buttonPosition.y + buttonHeight) {
			inside = false;
		}

		// Mouse is outside button
		if(!inside) {
			currentSprite = mouseOut;
		}

        // Mouse is inside button
        else {
            switch(event->type) {
                case SDL_MOUSEMOTION:
                    currentSprite = mouseOverMotion;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    currentSprite = mouseDown;
                    break;

                case SDL_MOUSEBUTTONUP:
                    currentSprite = mouseUp;
                    break;
            }
        }
    }
}

void Button::render(int x, int y) {
}