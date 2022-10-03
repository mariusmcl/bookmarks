#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
#define long long int BIGMAN;

int main(int argc, char *argv[])
{
    int *data = (int *)malloc(sizeof(int) * 100);
    printf("data[100] %d \n", data[100]);
    printf("data[10] %d \n", data[10]);
    printf("data[0] %d \n", data[1]);
    free(data);
    printf("data[100] %d \n", data[100]);

    printf("data[57] %d \n", data[57]);

    data[57] = 132;
    
    printf("data[57] %d \n", data[57]);


    printf("data[10] %d \n", data[10]);

    printf("data[0] %d \n", data[1]);
}