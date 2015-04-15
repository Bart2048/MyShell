/* 19:04 2015-04-15 Wednesday */
#include <stdio.h>
#include <unistd.h>

int fork_fun()
{
    pid_t pid1,pid2;

    pid1 = fork();
    if (pid1 < 0)
    {
        perror("Fail to fork!");
        return -1;
    }
    if (pid1 > 0)
    {
        pid2 = fork();
        if (pid1 < 0)
        {
            perror("Fail to fork!");
            return -1;
        }
        while(1);
    }
    else
    {
        sleep(5);
        return -1;
    }
    return 0;
}

int main(int argc, const char *argv[])
{
    fork_fun();
    return 0;
}
