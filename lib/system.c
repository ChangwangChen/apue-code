//
// Created by changwang on 3/18/20.
//
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>

int
local_system(const char *cmdstring)
{
    pid_t pid;
    int   status;

    if (cmdstring == NULL)
        return(1); /* always a command processor with UNIX */

    if((pid = fork()) < 0) {
        status = -1; /* probably out of processes */
    } else if (pid == 0) {
        execl("/bin/sh", "sh", "-c", cmdstring, (char*)0);
        _exit(127);
    } else {
        while(waitpid(pid, &status, 0) < 0) {
            if(errno != EINTR) {
                status = -1;
                break;
            }
        }
    }

    return(status);
}
