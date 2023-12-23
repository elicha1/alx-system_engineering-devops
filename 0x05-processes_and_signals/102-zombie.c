#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * infinite_while - Creates an infinite loop
 *
 * Return: Always returns 0
 */
int infinite_while(void)
{
    while (1)
    {
        sleep(1);
    }
    return (0);
}

/**
 * main - Creates 5 zombie processes
 *
 * Return: Always returns 0
 */
int main(void)
{
    pid_t zombie_pid;
    int i;

    for (i = 0; i < 5; i++)
    {
        zombie_pid = fork();

        if (zombie_pid == 0)
        {
            // Child process
            printf("Zombie process created, PID: %d\n", getpid());
            exit(0);
        }
        else if (zombie_pid < 0)
        {
            // Error handling if fork fails
            perror("Fork failed");
            return (1);
        }
    }

    infinite_while(); // Function to keep the program running

    return (0);
}
