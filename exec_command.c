#include "main.h"

/**
 * execute_command - executes command entered by user
 * @full_command: array of pointers to the commands
 * @args: argument vector
 * @envp: environment variable
 * @line: line number (nth iteration)
 * Return: 0 (on success)
 */

int execute_command(char **full_command, char *args, char **envp, size_t line)
{
	pid_t child;
	int status;
	/*char *actual_command;*/

	/*actual_command = locate_path(full_command[0], envp);*/
	child = fork();
	if (child == 0)
	{
		if (execve(full_command[0], full_command, envp) == -1)
		{
			_printf("%s: %d: %s: not found\n", args, line,
				full_command[0]);
			free_str(full_command);
			exit(0);
		}
	}
	else
		wait(&status);

	free_str(full_command);
	return (0);
}
