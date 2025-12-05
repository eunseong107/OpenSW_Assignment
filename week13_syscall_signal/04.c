#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include <stdio.h>
#include <stdlib.h>

void sigint_handler(int sig) {
    printf("[SIGINT handler] ------------\n");
    pid_t pid = fork();

    if(pid == 0) { // child
        char* const argv[] = {"ls", NULL};
        execve("/usr/bin/ls", argv, NULL);
    } else { // parent
        int wstatus;
        waitpid(pid, &wstatus, 0);
    }
}

void sigquit_handler(int sig) {
    printf("[SIGQUIT handler] ------------\n");
    pid_t pid = fork();

    if(pid == 0) { // child
        char* const argv[] = {"date", NULL};
        execve("/usr/bin/date", argv, NULL);
    } else { // parent
        int wstatus;
        waitpid(pid, &wstatus, 0);
    }
}

void sigalarm_handler(int sig) {
    printf("[SIGALARM handler] ------------\n");
        pid_t pid = fork();

    if(pid == 0) { // child
        char* const argv[] = {"whoami", NULL};
        execve("/usr/bin/whoami", argv, NULL);
    } else { // parent
        int wstatus;
        waitpid(pid, &wstatus, 0);
    }
    alarm(3);
}

int main() {

    struct sigaction sa_int;
    struct sigaction sa_quit;
    struct sigaction sa_alarm;

    sa_int.sa_handler = sigint_handler;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = 0;
    
    sa_quit.sa_handler = sigquit_handler;
    sigemptyset(&sa_quit.sa_mask);
    sa_quit.sa_flags = 0;

    sa_alarm.sa_handler = sigalarm_handler;
    sigemptyset(&sa_alarm.sa_mask);
    sa_alarm.sa_flags = 0;

    sigaction(SIGINT, &sa_int, NULL);
    sigaction(SIGQUIT, &sa_quit, NULL);
    sigaction(SIGALRM, &sa_alarm, NULL);

    alarm(3);

    for(;;) {
        sleep(1);
    }

    return 0;
}