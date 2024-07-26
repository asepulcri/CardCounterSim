#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char *textureSheet, SDL_Renderer *ren) {
    renderer = ren;
    objTexture = TextureManager::LoadTexture(textureSheet, ren);
}

void GameObject::update() {
    xpos = 0;
    ypos = 0;

    srcRect.h = 186;
    srcRect.w = 128;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x
}

void GameObject::render() {
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}