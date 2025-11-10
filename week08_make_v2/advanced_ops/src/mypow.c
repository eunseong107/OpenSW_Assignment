#include "advanced_ops.h"

int mypow(int a, int b) {
    int c = 1;
    for(int i = 0; i<b; i++) {
        c *= a;
    }
    printf("Here is pow().\n");
    return c;
}