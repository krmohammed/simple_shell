#include "main.h"

/**
 * main - entry to run commands entered by user
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment variable
 *
 * Return: 0 (Always)
 */

int main(int argc, char **argv, char **envp)
{
	char *prompt, *user_command = NULL, **full_command;
	ssize_t get_command;
	size_t n = 0;
	int i = 1, status_exit = 0;
	(void)argc;

	prompt = "$ ";

	if (isatty(STDIN_FILENO))
		_printf("%s", prompt);

	while ((get_command = getline(&user_command, &n, stdin)) != -1)
	{
		/*if (get_command == -1)
		{
			free(user_command);
			return (-1);
		}

		if (*user_command == '\n')
			continue;*/

		if (strlen(user_command) > 1 && all_spaces(user_command) != 0)
		{	
			full_command = tokens(user_command, " \n");
			if (full_command == NULL)
				continue;
			if (strcmp(full_command[0], "exit") == 0)
			{
				if (full_command[1])
					status_exit = atoi(full_command[1]);
				freeing(full_command);
				break;
			}
			execute_command(full_command, argv, envp, i);
			freeing(full_command);
		}
		i++;
		if (isatty(STDIN_FILENO) == 1)
			_printf("%s", prompt);
	}

	if (get_command == -1 && isatty(STDIN_FILENO) == 1)
		_printf("\n");

	free(user_command);
	return (status_exit);
}
