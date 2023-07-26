#include "main.h"


/**
 * perform_exit - excecute exit command.
 * @argv: pointer to command line variables vector.
 *
 * Return: NULL
 */

void perform_exit(char **argv)
{
	if (argv[0] != NULL)
	{
		if (strcmp(argv[0], "exit") == 0)
		{
			if (argv[1] != NULL)
			{
				int x = 0, is_digit = 0;
				char *ag_2 = argv[1];

				while (ag_2[x] != '\0' && is_digit == 0)
				{
					if (ag_2[x] >= '0' && ag_2[x] <= '9')
					{
						is_digit = 0;
					}
					else
					{
						is_digit = 1;
					}
					x++;
				}

				if (is_digit == 0)
				{
					int z, res = 0;

					for (z = 0; ag_2[z] != '\0'; z++)
					{
						res = res * 10 + (ag_2[z] - '0');
					}
					exit(res);
				}
			}
			exit(0);
		}
	}
}
