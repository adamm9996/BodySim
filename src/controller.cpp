//
// Created by adam on 02/01/16.
//

#include "controller.h"

controller::controller() {
    keyMap[SDLK_ESCAPE] = false;
    quitPressed = false;
}

controller::~controller() {
}

bool controller::pressed(SDL_Keycode button) {
    return keyMap[button];
}

bool controller::mousePressed(int mouseButton) {
    return SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(mouseButton);
}

bool controller::quit() {
    return (quitPressed || keyMap[SDLK_ESCAPE]);
}

void controller::takeInput() {
    SDL_Event windowEvent;
    while (SDL_PollEvent(&windowEvent)) {
        if (windowEvent.type == SDL_QUIT) {
            quitPressed = true;
        }
        else if (windowEvent.type == SDL_KEYDOWN) {
            keyMap[windowEvent.key.keysym.sym] = true;
        }
        else if (windowEvent.type == SDL_KEYUP) {
            keyMap[windowEvent.key.keysym.sym] = false;
        }
    }
}