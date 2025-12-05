#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct two_double {
    double a;
    double b;
} data;

void sigalarm_handler(int signo) {
    printf("%f, %f\n", data.a, data.b);
    alarm(1);
}

int main() {
    struct sigaction sa_alarm;
    struct two_double zeros = {0.0, 0.0}, ones = {1.0, 1.0};

    sa_alarm.sa_handler = sigalarm_handler;
    sigemptyset(&sa_alarm.sa_mask);
    sa_alarm.sa_flags = 0;

    if (sigaction(SIGALRM, &sa_alarm, NULL) == -1) {
        perror("sigaction error: ");
        exit(0);
    }

    alarm(1);

    sigset_t block_mask, old_mask;
    sigemptyset(&block_mask);
    sigaddset(&block_mask, SIGALRM);
    
    while(1) {

        if (sigprocmask(SIG_BLOCK, &block_mask, &old_mask) == -1) {
            perror("sigprocmask block error");
            exit(EXIT_FAILURE);
        }
        data = zeros;
        if (sigprocmask(SIG_SETMASK, &old_mask, NULL) == -1) {
            perror("sigprocmask unblock error");
            exit(EXIT_FAILURE);
        }

        if (sigprocmask(SIG_BLOCK, &block_mask, &old_mask) == -1) {
            perror("sigprocmask block error");
            exit(EXIT_FAILURE);
        }
        data = ones;
        if (sigprocmask(SIG_SETMASK, &old_mask, NULL) == -1) {
            perror("sigprocmask unblock error");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}