// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here    
    int rc = fork();
    char *args[] = {"/bin/ls", NULL};
    if (rc < 0){
        fprintf(stderr, "Fort failed\n");
        exit(1);
    } else if (rc == 0){
        execv(args[0], args);

        fprintf(stderr, "exec failed\n");
        exit(1);
    } else {
        int wc = waitpid(rc, NULL, 0); // Has the parent process wait until the child process is compelted
        printf("Program ended\n");
    }
    return 0;
}
