/* 19:36 2015-04-14 Tuesday */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>

int Count_Line(FILE *fp)
{
    char buf[123];
    int count = 0;
    while (fgets(buf,sizeof(buf),fp) != NULL)
    {
        if (buf[strlen(buf) - 1] == '\n')
        {
            count++;
        }
    }
    return count;
}

void Do_Log(FILE *fp)
{
    time_t t;
    struct tm *ptm;
    int count = 0;

    count = Count_Line(fp);
    while (1)
    {
        t = time(NULL);
        ptm = localtime(&t);

        fprintf(fp,"%4d: %d-%d-%d %d:%d:%d \n",count,ptm->tm_year+1900,ptm->tm_mon+1,ptm->tm_mday,\
            ptm->tm_hour,ptm->tm_min,ptm->tm_sec);
        fflush(fp);
        sleep(1);
        count++;
    }

    return;
}
int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr,"Usage : %s filename\n",argv[0]);
        return -1;
    }
    FILE *fp;

    fp = fopen(argv[1],"a+");
    if (fp == NULL)
    {
        fprintf(stderr,"Fail to open %s : %s\n",argv[1],strerror(errno));
        return -1;
    }

    Do_Log(fp);

    fclose(fp);

    return 0;
}
