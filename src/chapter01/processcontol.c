//
// Created by changwang on 4/18/18.
//
#include "apue.h"
#include <sys/wait.h>

static void sig_int(int); /* 获取信号 */

int main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if(signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal error");

    printf("%% "); /* 打印 % */
    while(fgets(buf, MAXLINE, stdin) != NULL) {
        if(buf[strlen(buf)-1] == '\n')
            buf[strlen(buf)-1] = 0; /* 替换输入结尾的换行符 */

        /* 开启新的进程来处理命令 */
        if((pid = fork()) < 0) {
            err_sys("fork error");
        } else if(pid == 0) {
            /* 子进程 */
            execlp(buf, buf, (char*)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        /* 父进程 */
        if((pid = waitpid(pid, &status, 0)) < 0)
            err_sys("waitpid error");
        printf("%% ");
    }

    exit(0);
}

void sig_int(int signo)
{
    printf("interrupt\n%% ");
}
