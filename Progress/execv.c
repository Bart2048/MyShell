/* 19:48 2015-04-15 Wednesday */
#include <stdio.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    pid_t pid;
    char *p_arry[] = {"ls","-l",NULL};
    printf("A\n");
    
    pid = vfork();
    if (pid == 0)
    {
        execv("/bin/ls",p_arry);
    }
    printf("B\n");
    return 0;
}

