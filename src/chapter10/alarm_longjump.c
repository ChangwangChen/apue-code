//
// Created by changwang on 3/23/20.
//

#include "apue.h"
#include <setjmp.h>

static void sig_alarm(int);
static jmp_buf env_alarm;

int
main(void)
{
    int n;
    char line[MAXLINE];

    if(signal(SIGALRM, sig_alarm) == SIG_ERR)
        err_sys("signal(SIGALRM) error");

    //longjmp() != 0 直接退出
    if(setjmp(env_alarm) != 0)
        err_quit("read time out");

    for( ; ;) {
        alarm(10);
        if((n == read(STDIN_FILENO, line, MAXLINE)) < 0)
            err_sys("read error");
        alarm(0);

//        write(STDOUT_FILENO, line, n);
        printf("%s\n", line);
    }

//    exit(0);
}

void
sig_alarm(int signo)
{
    longjmp(env_alarm, 1);
}

