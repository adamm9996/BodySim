//
// Created by adam on 28/12/15.
//

#ifndef BODYSIM_BODY_H
#define BODYSIM_BODY_H

#include <cmath>
typedef struct {
    double x, y;
} vec2;


class body {
public:
    body(double, double, double);
    vec2 getPos() const, getAcc() const, getVel() const;
    void setAcc(vec2), setPos(vec2), setVel(vec2);
    double getMass() const;
    double distance(body) const;
private:
    vec2 pos, acc, vel;
    double mass;
};

#endif //BODYSIM_BODY_H
