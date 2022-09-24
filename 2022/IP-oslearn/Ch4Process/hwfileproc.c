#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    int MYVARIABLE = 100;
    int rc = fork();
    MYVARIABLE = 103;
    if (rc < 0){  // fork failed (how??) --> exit??? hva skjer her..
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0){ // Det er som om child kalte fork(), og vil gå hit
        printf("hello, I am child (pid:%d). Value of x: %d\n", (int) getpid(), MYVARIABLE);
        MYVARIABLE = 101;
        printf("hello, I am child (pid:%d). Value of x: %d\n", (int) getpid(), MYVARIABLE);
        // close(STDOUT_FILENO);
        // open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
        // char *myargs[3];
        // myargs[0] = strdup("wc");   // Terminalkommando wc
        // myargs[1] = strdup("p3.c");  // Argumentet
        // myargs[2] = NULL;
        // execvp(myargs[0], myargs);
    } else {  // Det er hit parent, dvs. main-prosessen går
        MYVARIABLE = 102;
        int rc_wait = waitpid(rc, NULL, 0);
        printf("hello, I am parent of %d (rc_wait: %d) (pid:%d). Value of x: %d \n",
         rc, rc_wait, (int) getpid(), MYVARIABLE);
    }

}