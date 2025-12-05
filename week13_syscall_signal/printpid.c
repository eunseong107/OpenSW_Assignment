#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    for(;;) {
        printf("pid: %lu\n", (unsigned long)getpid());
        sleep(1);
    }

    return 0;
}