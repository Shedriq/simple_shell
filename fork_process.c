#include "shell.h"

/**
 * fork_process - function that creates a child process to
 * execute the given command (PATH).
 * @path: full path of the command to execute.
 * @tokens: command options.
 * @environ: user environment.
 * Return: 0 Success.
 */

int fork_process(char *path, char **tokens, char **environ)
{
	int child = 0;

	child = fork();
	if (child < 0)
	{
		free(path);
		return (1);
	}

	if (child == 0)
	{
		if (execve(path, tokens, environ) == 1)
		{
			return (1);
		}
	}
	else
	{
		wait(NULL);
		free(path);
		free(tokens);
	}

	return (0);
}
