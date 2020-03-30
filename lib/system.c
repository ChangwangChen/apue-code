//
// Created by changwang on 3/18/20.
//
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

int
local_system(const char *cmdstring)
{
    pid_t            pid;
    int              status;
    struct sigaction ignore, saveintr, savequit;
    sigset_t         chldmask, savemask;

    if (cmdstring == NULL)
        return(1); /* always a command processor with UNIX */

    ignore.sa_handler = SIG_IGN; /* ignore SIGINT, SIGQUIT */
    sigemptyset(&ignore.sa_mask);
    ignore.sa_flags = 0;
    if(sigaction(SIGINT, &ignore, &saveintr) < 0)
        return (-1);
    if(sigaction(SIGQUIT, &ignore, &savequit) < 0)
        return (-1);
    sigemptyset(&chldmask);
    sigaddset(&chldmask, SIGCHLD);
    if(sigprocmask(SIG_BLOCK, &chldmask, &savemask) < 0)
        return (-1);

    if((pid = fork()) < 0) {
        status = -1; /* probably out of processes */
    } else if (pid == 0) {
        /* child process */
        /* 在子进程中回复信号 SIGINT, SIGQUIT 的处理函数 */
        sigaction(SIGINT, &saveintr, NULL);
        sigaction(SIGQUIT, &saveintr, NULL);
        sigprocmask(SIG_SETMASK, &savemask, NULL);

        execl("/bin/sh", "sh", "-c", cmdstring, (char*)0);
        _exit(127);
    } else {
        /* parent child */
        while(waitpid(pid, &status, 0) < 0) {
            if(errno != EINTR) {
                status = -1;
                break;
            }
        }
    }

    /* restore previous signal actions & reset signal mask */
    /* parent process */
    /* 回复信号 SIGINT, SIGQUIT 的信号处理函数 */
    if(sigaction(SIGINT, &saveintr, NULL) < 0)
        return (-1);

    if(sigaction(SIGQUIT, &saveintr, NULL) < 0)
        return (-1);

    if(sigprocmask(SIG_SETMASK, &savemask, NULL) < 0)
        return (-1);

    return(status);
}
