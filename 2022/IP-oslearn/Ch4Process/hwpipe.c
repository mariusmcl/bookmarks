#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MSGSIZE 16

char* msg1 = "hello, world #1";
char* msg2 = "hello, world #2";
char* msg3 = "hello, world #3";

int main(int argc, char *argv[]){
    printf("hello world (pid:%d)\n", (int) getpid());
    int p[2], nbytes;
    char inbuf[MSGSIZE];

    printf("nbytes %d \n", nbytes);

    pipe(p);
    
    int rc = fork();

    printf("(pid:%d).\n", (int) getpid());


    if (rc < 0){  // fork failed (how??) --> exit??? hva skjer her..
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0){ // Det er som om child kalte fork(), og vil gå hit
        
        printf("hello, I am child (pid:%d).\n", (int) getpid());

        write(p[1], msg1, MSGSIZE);
		write(p[1], msg2, MSGSIZE);
		write(p[1], msg3, MSGSIZE);

		// Adding this line will
		// not hang the program
		// close(p[1]);
		wait(NULL);


        // 
        // char *myargs[3];
        // myargs[0] = strdup("wc");   // Terminalkommando wc
        // myargs[1] = strdup("p3.c");  // Argumentet
        // myargs[2] = NULL;
        // execvp(myargs[0], myargs);
    } else {  // Det er hit parent, dvs. main-prosessen går
        int rc_wait = waitpid(rc, NULL, 0);

        while ((nbytes = read(p[0], inbuf, MSGSIZE)) > 0)
			printf("% s\n", inbuf);
		if (nbytes != 0)
			exit(2);
		printf("Finished reading\n");
        // open("./HOMEWORK.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
        // close(STDOUT_FILENO);

        // int rc_wait = waitpid(rc, NULL, 0);
        printf("hello, I am parent of %d (rc_wait: %d) (pid:%d) \n",
        rc, rc_wait, (int) getpid());
    } 

}