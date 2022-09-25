// C program to illustrate
// pipe system call in C
// shared by Parent and Child
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define MSGSIZE 16
char* msg1 = "hello, world #1";
char* msg2 = "hello, world #2";
char* msg3 = "hello, world #3";

int main()
{
	char inbuf[MSGSIZE];
	int p[2], pid, nbytes;
    printf("p[0] %d\n", p[0]);
	if (pipe(p) < 0)
		exit(1);

	/* continued */
	if ((pid = fork()) > 0) {
		close(p[0]);
		printf("writing, (pid:%d)\n", getpid());
		write(p[1], msg1, MSGSIZE);
		write(p[1], msg2, MSGSIZE);
		write(p[1], msg3, MSGSIZE);

		close(p[1]);
		// Adding this line will
		// not hang the program
		// close(p[1]);
		// wait(NULL);
	}

	else {
		// Adding this line will
		// not hang the program
		printf("reading, (pid:%d)\n", getpid());
		close(p[1]);
		while ((nbytes = read(p[0], inbuf, MSGSIZE)) > 0)
			printf("% s\n", inbuf);
		if (nbytes != 0)
			exit(2);
		close(p[0]);
		printf("Finished reading\n");
	}
	return 0;
}
