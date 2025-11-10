#include <stdio.h>
#include <string.h>
#include "basic_ops.h"
#include "advanced_ops.h"

double calculate(char* op, double a, double b) {
    if (strcmp(op, "+") == 0) {
        return add(a, b);
    }
    else if (strcmp(op, "-") == 0) {
        return sub(a, b);
    }
    else if (strcmp(op, "*") == 0) {
        return mul(a, b);
    }
    else if (strcmp(op, "/") == 0) {
        return div(a, b);
    }
    else if (strcmp(op, "%") == 0) {
        return mymod(a, b);
    }
    else if (strcmp(op, "^") == 0) {
        return mypow(a, b);
    }
    else {
        printf("Unsupported operation: %s\n", op);
        return 0;
    }
}

int main() {
    double a, b;
    char op[3];

    printf("Enter experssion (e.g., 1 + 2): ");
    scanf("%lf %s %lf", &a, op, &b);
    printf("Result = %.2lf\n", calculate(op, a, b));
    return 0;
}