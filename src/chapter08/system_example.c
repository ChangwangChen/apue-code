//
// Created by changwang on 3/18/20.
//
#include "apue.h"
#include <sys/wait.h>

int
main(void)
{
    int status;

    if ((status = local_system("date")) < 0)
        err_sys("system() error");

    pr_exit(status);

    if ((status = local_system("nosuchcommand")) < 0)
        err_sys("system() error");

    pr_exit(status);

    if ((status = local_system("who; exit 44")) < 0)
        err_sys("system() error");

    pr_exit(status);

    exit(0);
}

