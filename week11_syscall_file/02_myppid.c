#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t my_pid;
    pid_t my_ppid;
    
    my_pid = getpid();
    my_ppid = getppid();

    printf("pid: %lu\n", (unsigned long)my_pid);
    printf("ppid: %lu\n", (unsigned long)my_ppid);

    return 0;
}