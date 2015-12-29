//
// Created by adam on 29/12/15.
//

#include <cmath>
#include <iostream>
#include "simulation.h"

using std::vector;
using std::sqrt;
using std::cout;
using std::endl;


vector<body> update(vector<body> bodies, double dt) {
    vector<vec2> newPos;
    vec2 acc, dist, pos, vel;
    double invr, invr3, force;
    for (auto i = bodies.begin(); i != bodies.end(); ++i) {
        acc.x = 0.0;
        acc.y = 0.0;
        for (auto j = bodies.begin(); j != bodies.end(); ++j) {
            if (i != j) {
                dist.x = j->getPos().x - i->getPos().x;
                dist.y = j->getPos().y - i->getPos().y;
                invr = 1.0 / sqrt(dist.x * dist.x + dist.y * dist.y);
                invr3 = invr * invr * invr;
                force = j->getMass() * invr3;
                acc.x += force * dist.x;
                acc.y += force * dist.y;
            }
        }
        pos.x = i->getPos().x + dt * i->getVel().x + 0.5 * dt * dt * acc.x;
        pos.y = i->getPos().y + dt * i->getVel().y + 0.5 * dt * dt * acc.y;
        vel.x = i->getVel().x + dt * acc.x;
        vel.y = i->getVel().y + dt * acc.y;
        newPos.push_back(pos);
        i->setAcc(acc);
        i->setVel(vel);
    }
    for (int k = 0; k != bodies.size(); k++) {
        bodies[k].setPos(newPos[k]);
    }
    return bodies;
}

vector<body> initialiseBodies() {
    vector<body> bodies;

    bodies.push_back(*(new body(1.0, -1.0, 1000.0)));
    bodies.push_back(*(new body(-1.0, 1.0, 1.0)));
    return bodies;
}