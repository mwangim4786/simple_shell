#include "main.h"

/**
 * perform_env - excecute env command.
 * @argv: pointer to command line variables vector.
 * @envp: pointer to command line variables vector.
 *
 * Return: NULL
 */

void perform_env(char **argv, char **envp)
{
	int j;

	if (argv[0] != NULL)
	{
		if (strcmp(argv[0], "env") == 0)
		{
			j = 0;
			while (envp[j] != NULL)
			{
				printf("%s\n", envp[j]);
				j++;
			}
		}
	}
}
