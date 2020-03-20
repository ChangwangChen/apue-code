//
// Created by changwang on 3/18/20.
//
#include "apue.h"

int
main(int argc, char **argv)
{
    int status;

    if (argc < 2)
        err_quit("command-line argument required");

    if ((status = local_system(argv[1])) < 0)
        err_sys("system() error");

    pr_exit(status);

    exit(0);
}
