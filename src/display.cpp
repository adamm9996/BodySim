//
// Created by adam on 28/12/15.
//


#include "display.h"

using std::vector;
using std::cout;
using std::endl;
using std::string;

SDL_Window* window;
SDL_GLContext glContext;
GLuint vbo, vao, ebo, tex, vertexShader, fragmentShader, shaderProgram;
GLint uniSquareTrans, posAttrib, colAttrib, texAttrib;

GLfloat squareVertices[] = {
//	 x		y	  r		g	  b     tX   tY
    -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
    -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
     0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
     0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f
};

GLuint squareElements[] = {0, 1, 2, 0, 2, 3};

void drawSquare(double x, double y, float size) {
    glm::mat4 squareTrans = glm::mat4();
    squareTrans = glm::translate(squareTrans, glm::vec3(size * (x + 0.5f) - 0.5f, size * (y + 0.5f) - 0.5f, 0.0f));
    squareTrans = glm::scale(squareTrans, size * glm::vec3(1.0f, 1.0f, 1.0f));
    glUniformMatrix4fv(uniSquareTrans, 1, GL_FALSE, glm::value_ptr(squareTrans));
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
void drawBodies(vector<body> bodies) {
    for (auto& b : bodies) {
        drawSquare(b.getPos().x, b.getPos().y, 0.01);
    }
}

void draw(vector<body> bodies) {
    SDL_GL_SwapWindow(window);
    glClearColor(0.0f, 0.5f, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawBodies(bodies);
}

void textDisplay(vector<body> bodies) {
    cout << "____________________" << endl << endl;
    for (auto& p : bodies) {
        cout << "acc: (" << p.getAcc().x << "," << p.getAcc().y << ")" << endl;
        cout << "vel: (" << p.getVel().x << "," << p.getVel().y << ")" << endl;
        cout << "pos: (" << p.getPos().x << "," << p.getPos().y << ")" << endl;
        for (auto& b : bodies) {
            if (&b != &p) {
                cout << "dist: " <<p.distance(b) << endl;
            }
        }
        cout << endl;
    }
    cout << "____________________" << endl;
}

void destroyDisplay() {
    glDeleteProgram(shaderProgram);
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
}

void initialiseWindow(int width, int height, string title) {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    glContext = SDL_GL_CreateContext(window);
}

void initialiseGL() {
    glewExperimental = GL_TRUE;
    glewInit();

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(squareVertices), squareVertices, GL_STATIC_DRAW);

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glBindFragDataLocation(shaderProgram, 0, "outColor");
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    posAttrib = glGetAttribLocation(shaderProgram, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(float), 0);

    colAttrib = glGetAttribLocation(shaderProgram, "color");
    glEnableVertexAttribArray(colAttrib);
    glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(2 * sizeof(float)));

    texAttrib = glGetAttribLocation(shaderProgram, "texcoord");
    glEnableVertexAttribArray(texAttrib);
    glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(5 * sizeof(float)));

    glGenBuffers(1, &ebo);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(squareElements), squareElements, GL_STATIC_DRAW);

    uniSquareTrans = glGetUniformLocation(shaderProgram, "square");

    glClearColor(0.0f, 0.5f, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
