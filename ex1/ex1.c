// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    //Initialize a clone of this process. It runs the code under this line 
    int clone = fork();
    
    // if clone returns a negative number the clone failed
    if (clone < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (clone == 0){ // if clone returns 0, the child process has been created
        printf("Child process: %d\n", x);
        x = 50;
        printf("Child process new x: %d\n", x);
    } else {
        printf("Parent process: %d\n", x);
        x = 150;
        printf("Parent process new x: %d\n", x);
    }

    return 0;
}
