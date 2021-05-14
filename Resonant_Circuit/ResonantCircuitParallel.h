//
// Created by jAdmin on 5/05/20.
//

#ifndef ASSN9_RESONANTCIRCUITPARALLEL_H
#define ASSN9_RESONANTCIRCUITPARALLEL_H

#include "ResonantCircuit.h"
class resonantCircuitParallel : public resonantCircuit{
private:
    double R, L, C;
    double calcR();
    double calcC();
    double calcL();
public:
    resonantCircuitParallel(double, double, double);
    void display();
};


#endif //ASSN9_RESONANTCIRCUITPARALLEL_H
