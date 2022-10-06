#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    // printf("vi er start \n");
    long long int PAGESIZE = 4 * 1024;
    // printf("vi er 1 \n");
    long long int jump = PAGESIZE / sizeof(int);
    // printf("vi er 2 \n");
    long long int  NUMPAGES = atoi(argv[1]);
    // printf("vi er 3 \n");
    int a[NUMPAGES * jump];
    // printf("vi er over \n");
    for (int i = 0; i < NUMPAGES * jump; i += jump)
    {
        a[i] += 1;
    }
    // printf("vi er her \n");
    struct timeval current_time;
    struct timeval final_time;
    gettimeofday(&current_time, NULL);
    for (int j = 0; j < 1024 * 1000; j++)
    {
        for (int i = 0; i < NUMPAGES * jump; i += jump)
        {
            a[i] += 1;
        }
    }
    
    gettimeofday(&final_time, NULL);

    /* printf("seconds : %ld\nmicro seconds : %ld\n",
    final_time.tv_sec - current_time.tv_sec,
    final_time.tv_usec - current_time.tv_usec); */

    printf("%ld, %ld\n",
    final_time.tv_sec - current_time.tv_sec,
    final_time.tv_usec - current_time.tv_usec);
}