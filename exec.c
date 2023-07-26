#include "main.h"



/**
 * exec - perform command execution.
 * @argv: pointer to command line variables vector.
 *
 * Return: NULL
 */


void exec(char **argv)
{
	char *argv_zero = NULL, *command = NULL;

	if (argv)
	{
		argv_zero = argv[0];
		command = get_location(argv_zero);
		if (execve(command, argv, NULL) == -1)
		{
			perror("./shell");
		}
	}
}
