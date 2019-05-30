// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?  Same as parent.
// What happens to the variable when both the child and parent change the value of x?  Each changes, but does not affect the value in the other.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    int child_fork = fork();
    printf("child_fork: %d\n", child_fork);
    if (child_fork == 0)
    {
        x++;
        printf("x in child process: %d\n", x);
    }
    else
    {
        x++;
        printf("x in parent process: %d\n", x);
    }
    return 0;
}
