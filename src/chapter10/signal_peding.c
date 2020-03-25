//
// Created by changwang on 3/25/20.
//

#include "apue.h"

static void sig_quit(int);

int
main(void)
{
    sigset_t newmask, oldmask, pendmask;

    if(signal(SIGQUIT, sig_quit) == SIG_ERR)
        err_sys("signal error");

    sigemptyset(&newmask); //init
    sigaddset(&newmask, SIGQUIT);
    if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
        err_sys("SIG_BLOCK error");

    sleep(5);

    if(sigpending(&pendmask) < 0)
        err_sys("sigpending error");
    if(sigismember(&pendmask, SIGQUIT))
        printf("\nSIGQUIT pending\n");

    if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        err_sys("restore error");
    printf("SIGQUIT unblocked\n");
    sleep(5);
    exit(0);
}

void
sig_quit(int signp)
{
    printf("caught SIGQUIT");
    if(signal(SIGQUIT, SIG_DFL) == SIG_ERR)
        err_sys("can't reset SIGQUIT");
}