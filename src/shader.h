//
// Created by adam on 01/01/16.
//

#ifndef BODYSIM_SHADER_H
#define BODYSIM_SHADER_H

#define GLSL(src) "#version 130\n" #src

#include <GL/glew.h>

extern const GLchar* vertexShaderSource, *fragmentShaderSource;

#endif //BODYSIM_SHADER_H
