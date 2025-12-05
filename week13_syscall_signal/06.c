#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

int main() {
    sigset_t block_mask, pending_mask;

    sigemptyset(&block_mask);
    sigaddset(&block_mask, SIGINT);

    if (sigprocmask(SIG_BLOCK, &block_mask, NULL) == -1) {
        perror("sigprocmask block error");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT blocked. Sleeping for 5 seconds...\n");
    printf("Try Ctrl + C during sleep.\n");
    sleep(5);

    if (sigpending(&pending_mask) == -1) {
        perror("sigpending error");
        exit(EXIT_FAILURE);
    }

    if (sigismember(&pending_mask, SIGINT)) {
        printf("\nSIGINT is pending\n");
    } else {
        printf("\nSIGINT is not pending\n");
    }
    
    if (sigprocmask(SIG_UNBLOCK, &block_mask, NULL) == -1) {
        perror("sigprocmask unblock error");
    }

    return 0;
}