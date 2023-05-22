#include "main.h"

/**
 * locate_path - gets the full path of an executable
 * @user_cmd: first element of command
 * @envp: array of environment variables
 *
 * Return: full path of user_cmd
 */

char *locate_path(char *user_cmd, char **envp)
{
	char *loc_path, *loc_path_cpy = NULL, *token, *right_path;
	int user_cmd_len, dir_len;
	struct stat buff_stat;

	user_cmd_len = _strlen(user_cmd);

	loc_path = _getEnv("PATH", envp);

	if (loc_path)
	{
		loc_path_cpy = malloc(sizeof(char) * _strlen(loc_path) + 1);
		if (loc_path_cpy == NULL)
			return (NULL);
		_strcpy(loc_path_cpy, loc_path);

		token = strtok(loc_path_cpy, ":");

		while (token)
		{
			dir_len = _strlen(token);

			right_path = malloc(dir_len + user_cmd_len + 2);
			if (right_path == NULL)
				return (NULL);

			_strcpy(right_path, token);
			_strcat(right_path, "/");
			_strcat(right_path, user_cmd);
			_strcat(right_path, "\0");

			if (stat(right_path, &buff_stat) == 0)
			{
				free(loc_path_cpy);
				return (right_path);
			}
			else
			{
				free(right_path);
				token = strtok(NULL, ":");
			}
		}

		if (stat(user_cmd, &buff_stat) == 0)
			return (user_cmd);

		return (NULL);
	}

	free(loc_path_cpy);
	return (NULL);
}
