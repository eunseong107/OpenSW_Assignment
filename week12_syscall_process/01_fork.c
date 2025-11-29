#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include <stdio.h>

int main() {
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == 0) { // child process
        printf("Child process PID: %lu\n", (unsigned long)getpid());
        printf("Child process PPID: %lu\n", (unsigned long)getppid());
        return 7;
    } else { // parent process
        int wstatus;

        waitpid(child_pid, &wstatus, 0);

        if (WIFEXITED(wstatus)) {
            printf("Child exited with status: %d\n", WEXITSTATUS(wstatus));
        }

        printf("Parent process PID: %lu\n", (unsigned long)getpid());
        printf("Parent process PPID: %lu\n", (unsigned long)getppid());
    }
    
    return 0;
}