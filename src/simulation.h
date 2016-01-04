//
// Created by adam on 29/12/15.
//

#ifndef BODYSIM_SIMULATION_H
#define BODYSIM_SIMULATION_H

#include <vector>
#include "body.h"

void update(std::vector<body>&, double);
std::vector<body> initialiseBodies();

#endif //BODYSIM_SIMULATION_H
