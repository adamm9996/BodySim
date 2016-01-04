//
// Created by adam on 29/12/15.
//

#include <cmath>
#include <iostream>
#include <chrono>
#include <random>
#include "simulation.h"

using std::vector;
using std::sqrt;
using std::cout;
using std::endl;


void update(vector<body>& bodies, double dt) {
    vector<vec2> newPos;
    vec2 acc, dist, pos, vel;
    double invr, invr3, force;
    double eps = 1;
    for (auto& i : bodies) {
        acc.x = 0.0;
        acc.y = 0.0;
        for (auto& j : bodies) {
            if (&i != &j) {
                dist.x = j.getPos().x - i.getPos().x;
                dist.y = j.getPos().y - i.getPos().y;
                //invr = 1.0 / i.distance(j) + eps;
                invr = 1.0 / sqrt(dist.x*dist.x + dist.y*dist.y + eps);
                invr3 = invr * invr * invr;
                force = j.getMass() * invr3;
                acc.x += force * dist.x;
                acc.y += force * dist.y;
            }
        }
        pos.x = i.getPos().x + dt * i.getVel().x + 0.5 * dt * dt * acc.x;
        pos.y = i.getPos().y + dt * i.getVel().y + 0.5 * dt * dt * acc.y;
        vel.x = i.getVel().x + dt * acc.x;
        vel.y = i.getVel().y + dt * acc.y;
        newPos.push_back(pos);
        //i.setAcc(acc);
        i.setVel(vel);
    }
    for (unsigned int k = 0; k != bodies.size(); k++) {
        bodies[k].setPos(newPos[k]);
    }
    return;
}

vector<body> initialiseBodiesRandom(double gravity) {
    vector<body> bodies;
    long int seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::minstd_rand0 generator(seed);
    const double RANGE = 100.0;
    const unsigned int COUNT = 50;
    for (int t = 0; t < COUNT; t++) {
        double x = static_cast <double> (generator()) / (RAND_MAX/RANGE);
        double y = static_cast <double> (generator()) / (RAND_MAX/RANGE);
        bodies.push_back(*(new body(x, y, gravity)));
    }
    return bodies;
}

vector<body> initialiseBodiesGrid(double gravity) {
    vector<body> bodies;
    for (double x = 0.0; x < 100.0; x += 10.0) {
        for (double y = 0.0; y < 100.0; y += 10.0) {
            bodies.push_back(*(new body(x, y, gravity)));
        }
    }
    return bodies;
}

vector<body> initialiseBodies() {
    const double gravity = 10.0;
    return initialiseBodiesRandom(gravity);
}