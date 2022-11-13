#include "shell.h"

char **_parse(char *str)
{
	int i = 0, size = 1024;
	char **tokens = NULL;
	char *token;

	tokens = malloc(sizeof(char*) * size);
	if (tokens == NULL)
		exit(0);
	token = strtok(str, "\n ");
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, "\n ");
		i++;
		if (i >= size)
		{
			size =+ size;
			tokens = realloc(tokens, size * sizeof(char*));
			if (tokens == NULL)
				exit(0);
		}
	}
	tokens[i] = NULL;
	free(tokens);
	return (tokens);
}
