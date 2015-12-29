
#include <iostream>
#include <thread>
#include "display.h"
#include "simulation.h"

using namespace std;

int main() {

    chrono::system_clock::time_point frameStart;
    vector<body> bodies = initialiseBodies();
    const int FRAME_LEN_MILLIS = 1000;
    while(true) {
        frameStart = std::chrono::system_clock::now();

        //draw(bodies);
        textDisplay(bodies);
        bodies = update(bodies, 1.0);
        std::this_thread::sleep_until(frameStart + std::chrono::milliseconds(FRAME_LEN_MILLIS));

    }

    return 0;
}