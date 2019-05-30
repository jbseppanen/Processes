// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main(void)
{
    char incoming_buf[MSGSIZE]; 
    int p[2];
    int pp = pipe(p);
    int child_fork = fork();
    if (child_fork == 0)
    {
        printf("Child process\n");
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }
    else
    {
        waitpid(child_fork, NULL, 0);
        printf("Parent process\n");
        for (int i = 0; i < 3; i++)
        {
            read(p[0], incoming_buf, MSGSIZE);
            printf("%s\n", incoming_buf);
        }
    }

    return 0;
}