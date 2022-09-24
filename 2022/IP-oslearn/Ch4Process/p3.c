#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0){  // fork failed (how??) --> exit??? hva skjer her..
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0){ // Det er som om child kalte fork(), og vil gå hit
        printf("hello, I am child (pid:%d)\n", (int) getpid());

        char *myargs[3];
        myargs[0] = strdup("wc");   // Terminalkommando wc
        myargs[1] = strdup("p3.c");  // Argumentet
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
        printf("Dette printer ikke \n");

    } else {  // Det er hit parent, dvs. main-prosessen går
        int rc_wait = waitpid(rc, NULL, 0);
        printf("hello, I am parent of %d (rc_wait: %d) (pid:%d) \n",
         rc, rc_wait, (int) getpid());
    }

}