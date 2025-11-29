#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <program path> [OPTION] ... \n", argv[0]);
        return 0;
    }

    pid_t child_pid;

    child_pid = fork();

    if(child_pid == 0) {
        execve(argv[1], &argv[1], NULL);
        
        return 1;
    } else {
        int wstatus;

        waitpid(child_pid, &wstatus, 0);

        if (WIFEXITED(wstatus)) {
            printf("Child exited with status: %d\n", WEXITSTATUS(wstatus));
        }
    }

    return 0;
}