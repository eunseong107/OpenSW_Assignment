#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include <stdio.h>

int main() {
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == 0) { // child process
        sleep(1);
        printf("Child process PID: %lu\n", (unsigned long)getpid());
        printf("Child process PPID: %lu\n", (unsigned long)getppid());
        return 0;
    } else { // parent process
        printf("Parent process PID: %lu\n", (unsigned long)getpid());
        printf("Parent process PPID: %lu\n", (unsigned long)getppid());
    }
    
}