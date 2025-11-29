#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int mysystem(const char *command) {
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == 0) {
        execl("/bin/sh", "sh", "-c", command, (char *) NULL);
    } else {
        int wstatus;
        waitpid(child_pid, &wstatus, 0);
    }
    return 0;
}

int main() {
    // system("ls -l | wc -l");
    // system("find . -name '*.c'");

    mysystem("ls -l | wc -l");
    mysystem("find . -name '*.c'");

    printf("Good bye\n");

    return 0;
}