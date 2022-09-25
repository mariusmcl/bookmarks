#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "common.h"
#include "common_threads.h"


int max;

volatile int counter = 0;  // Alle trådene har tilgang til denen variabelen

void *mythread(void *arg){
    char *letter = arg;
    int i;
    printf("%s: begin [addr of i: %p]\n", letter, &i);
    for (i=0; i<max; i++){
        counter = counter + 1;  // counter er delt minneobjekt
    }
    printf("%s: done \n", letter);
}

int main(int argc, char *argv[]){
    if (argc != 2){
        fprintf(stderr, "usage: main-first <loopcount>\n");
        exit(1);
    }
    max = atoi(argv[1]);  // All input er vel strenger (selv om de er tall)

    pthread_t p1, p2;
    printf("main: begin [counter = %d] [%x]\n", counter,
        (unsigned int) &counter);  // peker til minneaddr
    
}