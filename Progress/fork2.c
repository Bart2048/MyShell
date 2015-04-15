/* 19:09 2015-04-15 Wednesday */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int fork_write(int fd)
{
    char buf[1024];
    while (1)
    {
        fgets(buf,sizeof(buf),stdin);
        buf[strlen(buf)-1] = '\0';

        write(fd,buf,strlen(buf));
        if (strncmp(buf,"quit",4) == 0)
            break;
    }
    return 0;
}

int fork_read(int fd)
{
    int n;
    char buf[1024];
    while (1)
    {
        n = read(fd,buf,sizeof(buf));
        if (n == 0)
        {
            continue;
        }
        buf[n] = '\0';//注意结束标示


        printf("Read %d : %s\n",n,buf);
        if (strncmp(buf,"quit",4) == 4)
            break;
    }
    return 0;
}

int main(int argc, const char *argv[])
{
    if (argc < 2) 
    {
        fprintf(stderr,"Usage : %s filename\n",argv[0]);
        return -1;
    }
    int fd;

    fd = open(argv[1],O_WRONLY | O_CREAT | O_TRUNC,0666);
    if (fd < 0)
    {
        perror("Fail to open file");
        return -1;
    }

    pid_t pid;

    pid = fork();
    if (pid < 0)
    {
        perror("Fail to fork");
        return -1;
    }

    if (pid > 0)
    {
        fork_write(fd);
    }else
    {
        close(fd);
        fd = open(argv[1],O_RDONLY);
        if (fd < 0)
        {
            perror("Fail to open file");
            return -1;
        }
        fork_read(fd);
    }

    return 0;
}
