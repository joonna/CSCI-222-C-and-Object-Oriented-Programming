//
// Created by jAdmin on 5/05/20.
//

#ifndef ASSN9_RESONANTCIRCUIT_H
#define ASSN9_RESONANTCIRCUIT_H

#include <iostream>
using namespace std;

class resonantCircuit {
protected:
    double wI, B, k;
public:
    resonantCircuit(double, double, double);
    void display(){
        cout << "Resonant Circuit Display : Should not be seen" << endl;
    }
};


#endif //ASSN9_RESONANTCIRCUIT_H
