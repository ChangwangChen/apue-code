//
// Created by changwang on 1/8/20.
//

#include "apue.h"

int
main(void)
{
    if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        printf("cannot seek");
    else
        printf("can seek");

    return 0;
}
