#include <head.h>

void do_myshell(char *string)
{
    int i;
    char *p;
    char *pbuf[100];

    for (i = 0,p = string; *p != '\0'; i++)
    {
        pbuf[i] = p;
        while (*p != ' ' && *p != '\0')
        {
            p++; 
        }
        //if *p != '\0',then it must be ' '.
        if (*p != '\0')
        {
            *p = '\0';
            p++;
        }
    }
    pbuf[i] = NULL;

    for (i = 0;pbuf[i] != NULL; i++)
    {
        printf("%s\n",pbuf[i]);
    }

    if (execvp(pbuf[0],pbuf) < 0)
    {
        perror("Fail to execvp...");
        exit(EXIT_FAILURE);
    }
    return;
}
int main(int argc, const char *argv[])
{

    pid_t pid;
    char buf[1024];

    while (1)
    {
        fgets(buf,sizeof(buf),stdin);
        buf[strlen(buf)-1] = '\0';

        if (strncmp(buf,"quit",4) == 0)
        {
            break;
        }

        pid = fork();
        if (pid < 0)
        {
            perror("Fail to fork");
            exit(EXIT_FAILURE);
        }
        if (pid == 0)
        {
            do_myshell(buf);
        }
    }
    return 0;
}
