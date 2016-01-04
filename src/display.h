//
// Created by adam on 28/12/15.
//

#ifndef BODYSIM_DISPLAY_H
#define BODYSIM_DISPLAY_H

#define GLEW_STATIC
#define GLM_FORCE_RADIANS

#include <iostream>
#include <vector>
#include <string>
#include "body.h"
#include "shader.h"
#include <GL/gl.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void drawSquare(double, double, float);
void destroyDisplay();
void initialiseWindow(int, int, std::string);
void initialiseGL();
void draw(std::vector<body>);
void drawBodies(std::vector<body>);
void textDisplay(std::vector<body>);

#endif //BODYSIM_DISPLAY_H
