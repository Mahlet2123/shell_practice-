#include "shell.h"

int main()
{
	char **tokens = NULL;
	char *buffer = NULL;
	size_t bufsize;

	while (1)	
	{
		printf("#cisfun$ ");
		if (getline (&buffer, &bufsize, stdin) == EOF)
		{
			free(buffer);
			exit(0);
		}
		tokens = _parse(buffer);	
		if(fork() == 0)
		{
			if (execve(tokens[0], tokens, NULL) == -1)
			{
				perror("./shell");
				exit(0);
			}
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
		free(buffer);
		buffer = NULL;
	}	
	return (0);
}
