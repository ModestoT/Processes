// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
    // Your code here
    char inbuf[MSGSIZE];  // buffer to hold the incoming data that is being written
    int p[2]; // two-element array to hold the read and write file descriptors that are used by the pipe
    int rc;

    if (pipe(p) < 0){ //initializes the pipe and checks if it fails
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }

    rc = fork(); // initializes the fort and creates the child process

    if (rc < 0){
        fprintf(stderr, "Fort failed\n");
        exit(1);
    } else if (rc == 0){
        printf("Child process!\n");

        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    } else {
        printf("Parent process!\n");
        waitpid(rc, NULL, 0); // Has the parent process wait until the child process is compelted
        
        for (int i = 0; i < 3; i++) {
            // read 16 bytes of data from the read file descriptor 
            read(p[0], inbuf, MSGSIZE);
            printf("parent writing msg: %s\n", inbuf);
        }
        
        printf("Program ended\n");
    }
    return 0;
}
