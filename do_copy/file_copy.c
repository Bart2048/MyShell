/* 20:34 2015-04-14 Tuesday */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define Handle_Check(file) do{\
    fprintf(stderr,"Fail to open %s : %s\n",file,strerror(errno));\
    return -1;\
}while(0)

int main(int argc, const char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr,"Usage : %s Srcfile Destfile\n",argv[0]);
        return -1;
    }

    int Src;
    int Dest;
    int n;
    char buf[4096];

    Src = open(argv[1],O_RDONLY);
    if (Src < 0)
    {
        Handle_Check(argv[1]);
    }
    //be careful
    Dest = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0666);
    if (Dest < 0)
    {
        Handle_Check(argv[2]);
    }
    while (n = read(Src,buf,sizeof(buf)) != 0)
    {        
        write(Dest,buf,n);
    }

    close(Src);
    close(Dest);

    return 0;
}
