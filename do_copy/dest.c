/* 20:00 2015-04-14 Tuesday */
#include <stdio.h>
#include <string.h>
#include <errno.h>

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

    FILE *Src;
    FILE *Dest;
    int n;
    char buf[4096];

    Src = fopen(argv[1],"r");
    if (Src == NULL)
    {
        Handle_Check(argv[1]);
    }
    Dest = fopen(argv[2],"w");
    if (Dest == NULL)
    {
        Handle_Check(argv[2]);
    }

    while ((n=fread(buf,sizeof(char),sizeof(buf),Src)) != 0)
    {
        fwrite(buf,sizeof(char),n,Dest);
    }
    
    return 0;
}
