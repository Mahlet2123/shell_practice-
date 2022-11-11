#include "shell.h"
#include <stdio.h>
#include <string.h>

char **_parse(char *str)
{
	char *delim = "\n ";
	char *token;
	int size = 32; position = 0;
	char **tokens = malloc((int)size * sizeof(char*));

	if (tokens == NULL)
	{
		perror("allocation error");
		exit(EXIT_FAILURE);
	}
	token = strtok(str, delim);

	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= size)
		{
			size =+ size;
			tokens = realloc(tokens, size * sizeof(char*));
			if (tokens == NULL)
			{
				perror("allocation error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delim);
	}
	tokens[position] = NULL;
	return (tokens);
}
