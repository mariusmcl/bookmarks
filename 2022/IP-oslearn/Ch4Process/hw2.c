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
    printf("hello, I am pid (pid:%d). Value of x: %d\n", (int) getpid(), MYVARIABLE);

}