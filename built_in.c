#include "main.h"

/**
 * built - checks for built-in commands
 * @command: array of pointers pointing to the commands
 * @envp: array of pointers pointing to the env. variables
 *
 * Return: 1 (if successfull), 0 (otherwise)
 */

int built(char **command, char **envp)
{
	int i;

	if (_strcmp(command[0], "exit") == 0)
	{
		exit(1);
	}
	if (_strcmp(command[0], "env") == 0)
	{
		i = 0;
		while (envp[i])
			_printf("%s\n", envp[i++]);

		return (1);
	}

	return (0);
}
