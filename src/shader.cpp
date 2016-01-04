//
// Created by adam on 01/01/16.
//

#include "shader.h"

const GLchar* vertexShaderSource = GLSL (
    in vec2 position;
    in vec2 texcoord;
    in vec3 color;

    out vec3 Color;
    out vec2 Texcoord;

    uniform mat4 square;

    void main() {
        Texcoord = texcoord;
        Color = color;
        gl_Position = square * vec4(position, 0.0, 1.0);
    }
);

const GLchar* fragmentShaderSource = GLSL (
    in vec3 Color;
    in vec2 Texcoord;

    out vec4 outColor;

    uniform sampler2D tex;

    void main() {
        outColor = vec4(Color, 1.0) * texture(tex, Texcoord);
    }
);
