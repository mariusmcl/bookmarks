#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0){  // fork failed (how??) --> exit??? hva skjer her..
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0){ // lagde child prosess (tror jeg??)
        printf("hello, I am child (pid:%d)\n", (int) getpid());

    } else {
        printf("hello, I am parent of %d (pid:%d) \n", rc, (int) getpid());
    }

}