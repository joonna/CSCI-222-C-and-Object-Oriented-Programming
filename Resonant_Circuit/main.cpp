#include <iostream>
#include "ResonantCircuitSeries.h"
#include "ResonantCircuitParallel.h"
int main() {
    resonantCircuitSeries series(1.0, 2.0, 0.5);
    resonantCircuitParallel parallel(0.01, 2.0, 0.5);

    series.display();
    parallel.display();

    return 0;
}