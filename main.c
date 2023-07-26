#include "main.h"

/**
 * main - main function.
 * @argc: count integer.
 * @argv: arguments vector.
 * @envp: environment variables vector.
 *
 * Return: Always 0.
 */

int main(int argc, char **argv, char **envp)
{
	char *string = NULL, *string_copy = NULL,  *prompt = "cisfun$ ", *token;
	int i, status, num_tokens = 0;
	pid_t child_pid;
	size_t n = 0;
	ssize_t num_char = 0;
	const char *delim = " \n\t";
	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, prompt, strlen(prompt));

		num_char = getline(&string, &n, stdin);
		if (num_char == -1)
		{
			free(string);
			printf("\n");
			return (-1);
		}
		string_copy = malloc(sizeof(char) * num_char);
		if (string_copy == NULL)
		{
			perror("Error: Memory allocation error");
			return (-1);
		}
		strcpy(string_copy, string);
		token = strtok(string, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;

		argv = malloc(sizeof(char *) * num_tokens);
		token = strtok(string_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		perform_exit(argv);
		perform_env(argv, envp);

		if (argv[0] != NULL)
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error:");
				return (1);
			}
			if (child_pid == 0)
			{
				exec(argv);
			}
			else
			{
				wait(&status);
			}
		}

	}
	free(string);
	free(string_copy);

	return (0);
}
