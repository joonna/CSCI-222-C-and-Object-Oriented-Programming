//
// Created by jAdmin on 5/05/20.
//

#include "ResonantCircuitSeries.h"


resonantCircuitSeries::resonantCircuitSeries(double nW, double nB, double nK) : resonantCircuit(nW, nB, nK){
    R = calcR();
    L = calcL();
    C = calcC();
}
void resonantCircuitSeries::display() {
    cout << "Series" << endl;
    printf("w : %3.2lf && ", wI);
    printf("B : %3.2lf && ", B);
    printf("k : %3.2lf\n", k);

    printf("R : %3.2lf && ", R);
    printf("L : %3.2lf && ", L);
    printf("C : %3.2lf\n", C);

}

double resonantCircuitSeries::calcR(){
    return (double)1/k;
}
double resonantCircuitSeries::calcL(){
    return calcR()/B;
}
double resonantCircuitSeries::calcC(){
    return (double)1/(wI*wI*calcL());
}