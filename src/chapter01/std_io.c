#include "apue.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
    int count = 0, i;
    printf("当前进程Id: %ld, 父进程ID: %ld\n", getpid(), getppid());
    for (i = 1; i < 4; ++i) {  //通过for循环执行3次fork
      fork();
      printf("当前count的值: %d\n", ++count);
    }
    printf("当前进程Id: %ld, 父进程ID: %ld\n", getpid(), getppid());
    return 0;
}