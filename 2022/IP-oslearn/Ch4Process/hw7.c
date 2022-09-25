#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0){  // fork failed (how??) --> exit??? hva skjer her..
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0){ // Det er som om child kalte fork(), og vil gå hit
        close(STDOUT_FILENO);
        printf("hello\n");
		printf("childHello, (pid:%d)\n", getpid());
    } else {  // Det er hit parent, dvs. main-prosessen går
        int rc_wait = waitpid(rc, NULL, 0);

		printf("parentGoodbye, (pid:%d)\n", getpid());
        printf("goodbye\n");

        // printf("hello, I am parent of %d (rc_wait: %d) (pid:%d) \n",
        // rc, rc_wait, (int) getpid());
    } 

}