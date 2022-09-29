#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("pid: %d\n", getpid());
    int qq = atoi(argv[1]);
    int bigarr[qq * 1024 * 1000];
    printf("sizeof bigarr (MB) %lu\n", sizeof(bigarr) / (1024 * 1000));
    for (int i = 0; i < qq * 1024 * 1000; i++)
    {
        if (i % 100000 == 0)
        {
            printf("on line (%d), value of array (%d)\n", i, bigarr[i]);
            sleep(1);
        }
    }

}