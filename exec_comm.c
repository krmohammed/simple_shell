#include "main.h"

/**
 * execute_command - executes command entered by user
 * @full_command: array of pointers to the commands
 * @argv: argument vector
 * @envp: environment variable
 * @num: line number
 *
 */

void execute_command(char **full_command, char **argv, char **envp, int num)
{
	int child, status, builts;
	char *actual_command;

	builts = built(full_command);
	if (builts == -1)
	{
		print_error(argv[0], num, full_command[0], "not found\n");
		return;
	}
	else if (builts == 0)
		return;
	if (access(full_command[0], X_OK) == 0)
	{
		actual_command = malloc(sizeof(char) * strlen(full_command[0]) + 1);
		if (actual_command == NULL)
			return;
		actual_command = full_command[0];
	}
	else
	{
		actual_command = locate_path(full_command[0], envp);
		if (actual_command == NULL)
		{
			print_error(argv[0], num, full_command[0], "not found");
			return;
		}
	}
	if (access(actual_command, X_OK) != 0)
		return;
	child = fork();
	if (child == -1)
		print_error(argv[0], num, "fork", "Can't creat another process");
	else if (child == 0)
	{
		if (execve(actual_command, full_command, envp) == -1)
			perror(full_command[0]);
	}
	else
		wait(&status);
	free(actual_command);
}

/**
 * print_error - prints an error message
 * @cmd: command typed by user
 * @num: line number
 * @error: specific error
 * @error_msg: error message
 *
 */

void print_error(char *cmd, int num, char *error, char *error_msg)
{
	dprintf(STDERR_FILENO, "%s: %i: %s: %s\n", cmd, num, error, error_msg);
}

/**
 * all_spaces - checks if all inputs are spaces
 * @inp: user input command
 *
 * Return: 0 if all are spaces, 1 otherwise
 */

int all_spaces(char *inp)
{
	unsigned int j = 0;

	while (inp[j] != '\n' && inp[j] != '\0')
	{
		if (inp[j] != ' ' && inp[j] != '\t')
			return (1);
		j++;
	}
	return (0);
}
