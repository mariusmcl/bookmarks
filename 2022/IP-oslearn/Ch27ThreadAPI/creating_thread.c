#include <pthread.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct __myarg_t {
    int a;
    int b;
} myarg_t;


void *mythread(void *arg){
    myarg_t *m = (myarg_t * ) arg;  // Dette er en unpacking av args?
    printf("%d %d (pid: %d)\n", m->a, m->b, getpid());
}

int main (int argc, char *argv[]){
    pthread_t p;
    myarg_t args = {10, 20};


    int rc = pthread_create(&p, NULL, mythread, &args);
    assert(rc == 0);

    // fjerner man denne så vil programmet stoppe før thread
    // har executed --> kan føre til problemer med I/O osv!
    (void) pthread_join(p, NULL);  
    printf("done (pid: %d)\n", getpid());
    return 0;
}