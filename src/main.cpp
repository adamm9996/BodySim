#include <iostream>
#include <thread>
#include "display.h"
#include "simulation.h"
#include "controller.h"

using namespace std;

int main() {
    const int FRAME_LEN_MILLIS = 33, WIDTH = 600, HEIGHT = 600;
    const string TITLE = "Hello world";
    chrono::system_clock::time_point frameStart;
    vector<body> bodies = initialiseBodies();
    controller controller;
    bool running = true;

    initialiseWindow(WIDTH, HEIGHT, TITLE);
    initialiseGL();


    while (running) {
        //frameStart = std::chrono::system_clock::now();

        controller.takeInput();
        running = !controller.quit();
        update(bodies, 0.1);
        draw(bodies);
        //textDisplay(bodies);

       // std::this_thread::sleep_until(frameStart + std::chrono::milliseconds(FRAME_LEN_MILLIS));
    }

    destroyDisplay();
    return 0;
}
