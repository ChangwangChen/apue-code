//
// Created by changwang on 3/18/20.
//
#include "apue.h"

int
main(void)
{
    pid_t pid;

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid != 0) {
        sleep(2);
        exit(2);
    }

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid != 0) {
        sleep(4);
        abort();
    }

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid != 0) {
        execl("/bin/dd", "dd", "if=/ect/passwd", "of=/dev/null", NULL);
        exit(7);
    }

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid != 0) {
        sleep(8);
        exit(0);
    }

    sleep(6);
    kill(getpid(), SIGKILL);
    exit(6);
}
