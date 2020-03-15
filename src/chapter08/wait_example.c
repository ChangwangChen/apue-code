//
// Created by changwang on 3/11/20.
//
#include "apue.h"
#include <sys/wait.h>

int
main(void)
{
    pid_t pid;
    int   status;

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0) /* child process */
        exit(7);

    if (wait(&status) != pid) /* parent process, wait child */
        err_sys("wait error");
    pr_exit(status);         /* and print its status */

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)
        abort(); /* child process, generate SIGABRT */

    if (wait(&status) != pid) /* wait for child */
        err_sys("wait error");
    pr_exit(status);

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)
        status /= 0;   /* child process, divide by 0 generates SIGFPE */

    if (wait(&status) != pid) /* wait for child process */
        err_sys("wait error");
    pr_exit(status);

    exit(0);
}

