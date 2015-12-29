//
// Created by adam on 28/12/15.
//

#include "display.h"

using std::vector;
using std::cout;
using std::endl;

void draw(vector<body> bodies) {

}

void textDisplay(vector<body> bodies) {
    cout << "____________________" << endl;
    for (auto& p : bodies) {
        cout << "acc: (" << p.getAcc().x << "," << p.getAcc().y << ")" << endl;
        cout << "vel: (" << p.getVel().x << "," << p.getVel().y << ")" << endl;
        cout << "pos: (" << p.getPos().x << "," << p.getPos().y << ")" << endl << endl;
    }
    cout << "____________________" << endl;
}