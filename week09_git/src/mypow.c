#include "myops.h"

double mypow(double a, double b) {
    printf("This is mypow().\n");
    
    double c = 1;

    for(int i = 0; i < b; i++) {
        c *= a;
    }
    return c;
}