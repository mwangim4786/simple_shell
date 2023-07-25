#include "main.h"

/*
 * get_location - populates the command's path.
 * @argv_zero: pointer to env. variables list.
 *
 * Return: NULL
*/


char *get_location(char *argv_zero)
{
	char *path, *path_copy, *path_token, *file_path;
	int argv_zero_length, dir_len;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		path_copy = strdup(path);
		argv_zero_length = strlen(argv_zero);
		path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			dir_len = strlen(path_token);
			file_path = malloc(argv_zero_length + dir_len + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, argv_zero);
			strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		if (stat(argv_zero, &buffer) == 0)
		{
			return (argv_zero);
		}
		return (NULL);
	}
	return (NULL);
}
