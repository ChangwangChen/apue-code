//
// Created by changwang on 1/8/20.
//
#include "apue.h"
#include <fcntl.h>

char str1[] = "abcdefghij";
char str2[] = "HBCDEFGHIJ";

int
main(void)
{
    int fd;

    if((fd = creat("file.hole", FILE_MODE)) == -1)
        err_sys("create error");

    if(write(fd, str1, 10) != 10)
        err_sys("str1 write error");

    if(lseek(fd, 16384, SEEK_SET) == -1)
        err_sys("lseek error");

    printf("Offset: %lu\n", lseek(fd, 0, SEEK_CUR));

    if(write(fd, str2, 10) != 10)
        err_sys("str2 write error");

    exit(0);
}