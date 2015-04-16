/* 19:25 2015-04-16 Thursday */
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
    int value;
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0)
    {
        sleep(3);
        exit(EXIT_SUCCESS);
    }

    if (pid > 0)
    {
        while (1)
        {
            value = waitpid(pid,&status,WNOHANG);
            
            if (value == 0)
            {
                sleep(1);
                printf("The child process is not exit\n");
                continue;
            }else{
                printf("The child process is  exit\n");
                break;
            }
        }

    }
    return 0;
}
