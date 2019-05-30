// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    int rc = fork();

    if (rc < 0){
        fprintf(stderr, "Fort failed\n");
        exit(1);
    } else if (rc == 0){ // child process
        printf("Hello!\n");
    } else {
        int wc = waitpid(rc, NULL, 0); // Has the parent process wait until the child process is compelted
        printf("Goodbye\n");
    }
    

    return 0;
}
