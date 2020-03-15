//
// Created by changwang on 3/11/20.
//
#include "apue.h"
#include <sys/wait.h>

int
main(void)
{
    pid_t   pid;
    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0){ /* child process */
        if((pid = fork()) < 0)
            err_sys("fork error");
        else if (pid > 0)
            exit(0);

        //this code will be execute by the second fork's child process
        sleep(2);
        printf("second child process, parent pid = %d\n", (long)getppid());
        exit(0);
    }

    if(waitpid(pid, NULL, 0) != pid)
        err_sys("waitpid error");

    exit(0);
}

