//
// Created by jAdmin on 5/05/20.
//

#include "ResonantCircuitParallel.h"

resonantCircuitParallel::resonantCircuitParallel(double nW, double nB, double nK) : resonantCircuit(nW, nB, nK){
    R = calcR();
    L = calcL();
    C = calcC();
}
void resonantCircuitParallel::display() {
    cout << "Parallel" << endl;
    printf("w : %3.2lf && ", wI);
    printf("B : %3.2lf && ", B);
    printf("k : %3.2lf\n", k);

    printf("R : %3.2lf && ", R);
    printf("L : %3.2lf && ", L);
    printf("C : %3.2lf\n", C);

}

double resonantCircuitParallel::calcR(){
    return k;
}
double resonantCircuitParallel::calcL(){
    return (double)1/(wI*wI*C);
}
double resonantCircuitParallel::calcC(){
    return (double)1/(B*R);
}