//
// Created by changwang on 3/23/20.
//
#include "apue.h"

static void sig_user(int); /* one handler for both signals */

int
main(void)
{
    if(signal(SIGUSR1, sig_user) == SIG_ERR)
        err_sys("can't catch SIGUSER1");
    if(signal(SIGUSR2, sig_user) == SIG_ERR)
        err_sys("can't catch SIGUSER2");

    for ( ; ; )
        pause();
}

static void
sig_user(int signo)
{
    if(signo == SIGUSR1)
        printf("received SIGUSER1\n");
    else if(signo == SIGUSR2)
        printf("received SIGUSER@\n");
    else
        err_dump("received signal %d\n", signo);
}
