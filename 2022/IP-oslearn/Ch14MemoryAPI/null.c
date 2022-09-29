#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *ptr = (int *) malloc(sizeof(int));
    printf("ptrderefval: %d\n", *ptr);
    printf("ptr: %d\n", ptr);
    ptr = NULL;
    printf("ptr dereference val: %d\n", *ptr);
}