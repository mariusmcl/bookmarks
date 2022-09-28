#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

int main()
{
    long long time;
    time = -clock();
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    // printf("current TimeofDay: (%ld)s (%d) usec\n",
    //          current_time.tv_sec, current_time.tv_usec);
    int max = 100;
    int diffs = 0;
    for(int i = 0; i < max; i++){
        int prev = current_time.tv_usec;
        gettimeofday(&current_time, NULL);
        diffs += current_time.tv_usec - prev;
        printf("diff (%d)\n", diffs);
    }
    printf("diffs: (%d)\n", diffs / max);
    for (int i = 0; i < max; i++)
    {
        read(0, NULL, 0);
        time += clock();
    }
    printf("Took time: (%lld) microseconds\n", time / max);
}