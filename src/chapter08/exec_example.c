//
// Created by changwang on 3/16/20.
//
#include "apue.h"
#include <sys/wait.h>

char *env_init[] = {"USER=unknown", "PATH=/tmp", NULL};

int
main(void)
{
    pid_t pid;

    if((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        if(execle("/changwang/Code/apue-code/cmake-build/bin/echoall", "echoall", "myarg1",
                "MYARG2", (char*)0, env_init) < 0)
            err_sys('execle error');
    }

    if(waitpid(pid, NULL, 0) < 0) {
        err_sys("wait error");
    }

    if((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        if(execlp("echoall", "echoall", "only 1 arg", (char*)0) < 0)
            err_sys("execlp error");
    }

    exit(0);
}
