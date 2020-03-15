//
// Created by changwang on 3/9/20.
//
#include "apue.h"

int     globalval = 6;  /* external variable in initialized data */
char    buf[] = "a write to stdout\n";

int
main(void)
{
    int var; /* automatic variable on the stack */
    pid_t pid;

    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1)
        err_sys("write error");
    printf("before fork:\n"); /* we don't flush stdout */

    if ((pid = fork()) < 0) {
        err_sys("fork error\n");
    } else if (pid == 0) { /* child process */
        globalval++;
        var++;
    } else {
        sleep(2); /* parent process */
    }

    printf("pid = %ld, globalval = %d, var = %d\n", (long)getpid(), globalval, var);
    exit(0);
}


