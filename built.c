#include "main.h"

/**
 * built - checks for built-in commands
 * @command: array of pointers pointing to the commands
 *
 * Return: 1 (if successfull), 0 (otherwise)
 */

int built(char **command)
{
	int i = 0;

	built_t builtin[] = {
		{"env", environ_printer},
		{NULL, NULL}
	};

	while (builtin[i].command != NULL)
	{
		if (strcmp(command[0], builtin[i].command) == 0)
		{
			if (builtin[i].function(command) == -1)
				return (-1);
			return (0);
		}
		i++;
	}

	return (1);
}

/**
 * environ_printer - prints all environment variables
 * @args: pointer to array of env variables
 *
 * Return: 0
 */

int environ_printer(char **args)
{
	int j = 0;

	(void)args;
	while (environ[j])
	{
		_printf("%s\n", environ[j++]);
	}
	return (0);
}
