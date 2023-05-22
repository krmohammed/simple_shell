#include "main.h"

/**
 * execute_command - executes command entered by user
 * @full_command: array of pointers to the commands
 * @argv: argument vector
 * @envp: environment variable
 *
 * Return: 0 (on success)
 */

int execute_command(char **full_command, char **argv, char **envp)
{
    pid_t child;
    int status;
    char *actual_command;

    actual_command = locate_path(full_command[0], envp);

    child = fork();

    if (child == 0)
    {
        if (execve(actual_command, full_command, envp) == -1)
        {
            _printf("%s: No such file or directory\n", argv[0]);
            exit(1);
        }
    }
    else
        wait(&status);

    return (0);
}
