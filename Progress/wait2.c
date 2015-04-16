/* 19:25 2015-04-16 Thursday */
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
    int value;
    pid_t pid1,pid2;
    int status;

    pid1 = fork();

    if (pid1 == 0)
    {
            printf("child1 PID : %d  PPID : %d\n",getpid(),getppid());
        sleep(3);
        exit(0x123456);
    }

    if (pid1 > 0)
    {
        pid2 = fork();
        
        if (pid2 == 0)
        {
            printf("child2 PID : %d  PPID : %d\n",getpid(),getppid());
        }
        while (1)
        {
            printf("wait....\n");
            value = wait(&status);
            printf("value = %d\n",value);
            
            if (WIFEXITED(status))
            {
                printf("The child process terminated normally,return value = %#x\n",WEXITSTATUS(status));
            }else if(WIFSIGNALED(status)){
               printf("The child process terminated by signal,signum = %d\n",WTERMSIG(status));
            }
            sleep(1);
        }

    }
    return 0;
}
