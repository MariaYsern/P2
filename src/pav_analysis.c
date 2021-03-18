#include <math.h>
#include "pav_analysis.h"

float compute_power(const float *x, unsigned int N) {
    float potenciadB=0;
    for (int n=0; n<N; n++){
        potenciadB = pow(x[n],2) + potenciadB;
    }
    potenciadB = potenciadB / N;
    potenciadB = 10*log10(potenciadB);
    return potenciadB;
}

float compute_am(const float *x, unsigned int N) {
    float ampl=0;
    for (int n=0; n<N; n++){
        ampl = fabs(x[n]) + ampl;
    }
    ampl = ampl / N;
    return ampl;
}

float compute_zcr(const float *x, unsigned int N, float fm) {
    float zcr=0;
    for (int n=1; n<N; n++){
        if ((x[n]<0 && x[n-1]>0) || (x[n]>0 && x[n-1]<0)){
            zcr=zcr+1;
        }
    }
    zcr = (fm * zcr) / (2*(N-1));
    return zcr;
}