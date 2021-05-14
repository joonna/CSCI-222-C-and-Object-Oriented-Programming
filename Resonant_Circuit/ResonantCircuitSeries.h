//
// Created by jAdmin on 5/05/20.
//

#ifndef ASSN9_RESONANTCIRCUITSERIES_H
#define ASSN9_RESONANTCIRCUITSERIES_H

#include "ResonantCircuit.h"

class resonantCircuitSeries : public resonantCircuit {
private:
    double R, L, C;
    double calcR();
    double calcC();
    double calcL();
public:
    resonantCircuitSeries(double, double, double);
    void display();
};


#endif //ASSN9_RESONANTCIRCUITSERIES_H
