//
// Created by adam on 02/01/16.
//

#ifndef BODYSIM_CONTROLLER_H
#define BODYSIM_CONTROLLER_H

#include <SDL2/SDL.h>
#include <map>

class controller
{
public:
    controller();
    virtual ~controller();
    bool pressed(SDL_Keycode);
    bool mousePressed(int);
    void takeInput();
    bool quit();
private:
    std::map<SDL_Keycode, bool> keyMap;
    bool quitPressed;
};


#endif //BODYSIM_CONTROLLER_H
