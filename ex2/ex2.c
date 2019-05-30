// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor returned by `fopen()`? Yes
// What happens when they are written to the file concurrently?  Both are able to write.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;

    f = fopen("text.txt", "r+");
    printf("File descriptor: %d\n", fileno(f));
    int child_fork = fork();
    if (child_fork == 0)
    {
        printf("Child file descriptor: %d\n", fileno(f));
        fprintf(f, "Child process line.\n");
    }
    else
    {
        printf("Parent file descriptor: %d\n", fileno(f));
        fprintf(f, "Parent process line.\n");
    }

    fclose(f);

    return 0;
}
