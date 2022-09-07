#include "shell.h"

/**
 * prompt_no_interactive - function that gets a string from the
 * command line.
 * @name_file: name of the executable file
 * Return: char pointer that contains the string
 */

char *prompt_no_interactive(char *name_file)
{
	char *line = NULL;
	int input = 0;
	size_t line_size = 0;

	input = getline(&line, &line_size, stdin);

	if (input == -1)
	{
		if (errno == EINVAL || errno == ENOMEM)
		{
			perror(name_file);
		}
		free(line);
		line_size = 0;
		return (NULL);
	}
	return (line);
}
