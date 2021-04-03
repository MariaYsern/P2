#include <math.h>
#include "pav_analysis.h"

float compute_power(const float *x, unsigned int N) {
    float power = 0;
    for(int i=0; i<N; i++) {
        power += pow(x[i],2);
    }
    return 10*log10(power/N);
}

float compute_am(const float *x, unsigned int N) {
    float am=0;
    for(int i=0; i<N; i++) {
        am += fabs(x[i]);
    }
    return am/N;
}

float compute_zcr(const float *x, unsigned int N, float fm) {
    float zcr=0;
    for(int i=1; i<N; i++) {
        if((x[i]<0 && x[i-1]>0) || (x[i]>0 && x[i-1]<0)){
            zcr+=1;
        }
    }
    return zcr*fm/(2*(N-1));
}