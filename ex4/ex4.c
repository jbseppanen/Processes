// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?  Different systems, different format inputs and output needed.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    int child_fork = fork();
    if (child_fork == 0)
    {
        printf("Child process\n");
        char *args[] = {"/bin/ls", NULL};
        execvp(args[0], args);
        // execv(args[0], args);
        // execl(args[0], "", NULL);
        // execlp(args[0], args[0], "-l", (char *) NULL);
    }
    else
    {
        printf("Parent process\n");
    }
    return 0;
}
