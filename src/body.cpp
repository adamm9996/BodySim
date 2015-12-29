//
// Created by adam on 28/12/15.
//

#include "body.h"

body::body(double x, double y, double mass) {
    this->pos.x = x;
    this->pos.y = y;
    this->acc.x = 0.0;
    this->acc.y = 0.0;
    this->vel.x = 0.0;
    this->vel.y = 0.0;
    this->mass = mass;
}

void body::setAcc(vec2 acc) {
    this->acc = acc;
}

void body::setVel(vec2 vel) {
    this->vel = vel;
}

void body::setPos(vec2 pos) {
    this->pos = pos;
}

double body::getMass() const {
    return this->mass;
}

vec2 body::getPos() const {
    return this->pos;
}

vec2 body::getAcc() const {
    return this->acc;
}

vec2 body::getVel() const {
    return this->vel;
}