#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define SIZE (100 * 1024 * 1024)

int main(void)
{
    char *memory;
    pid_t pid;

    memory = malloc(SIZE);

    if (memory == NULL)
    {
        perror("malloc");
        return 1;
    }

    for (size_t i = 0; i < SIZE; i += 4096)
    {
        memory[i] = 1;
    }

    printf("Parent: allocated 100 MB\n");

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        free(memory);
        return 1;
    }

    if (pid == 0)
    {
        printf("Child PID: %d\n", getpid());
        printf("Child: modifying one byte every 4096 bytes...\n");

        for (size_t i = 0; i < SIZE; i += 4096)
        {
            memory[i] = 2;
        }

        printf("Child: modification complete\n");
        printf("Child: sleeping for 30 seconds...\n");

        sleep(30);

        free(memory);
        exit(0);
    }
    else
    {
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);

        printf("Parent: waiting for child...\n");

        wait(NULL);

        printf("Parent: child process finished\n");

        free(memory);
    }

    return 0;
}
