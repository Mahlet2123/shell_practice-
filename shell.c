#include "shell.h"

int main(int ac, char **av)
{
	int i = 0;
	char *str;
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
		
		tokens = malloc(sizeof(buffer) * 1024); 
		if (tokens == NULL)
			exit(0);

		str = strtok(buffer, "\n ");
		while (str != NULL)
		{
			tokens[i] = str;
			str = strtok(NULL, "\n ");
			i++;
		}

		/**av = _parse(buffer);*/
			
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
		free(tokens)
		buffer = NULL;
	}	
	return (0);
}
