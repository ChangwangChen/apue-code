//
// Created by changwang on 1/7/20.
//
#include "apue.h"

int
main(void)
{
    int n;
    while((n = getc(stdin)) != EOF)
        if(putc(n, stdout) == EOF)
            err_sys("output error");

    if(ferror(stdin))
        err_sys("input error");

    return 0;
}

