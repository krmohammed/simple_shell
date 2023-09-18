#include "main.h"

/**
 * _getEnv - gets the value of an environment variable
 * @path: specific environment variable
 * @envp: array of environment variables
 *
 * Return: pointer to the value of the env. variable
 */

char *_getEnv(char *path, char **envp)
{
	int i;

	if (path == NULL || envp == NULL)
		return (NULL);

	for (i = 0; envp[i] != NULL; i++)
	{
		if (strncmp(envp[i], path, strlen(path)) == 0 && envp[i][strlen(path)])
			return (envp[i] + strlen(path) + 1);
	}

	return (NULL);
}
