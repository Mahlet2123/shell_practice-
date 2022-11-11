#include "shell.h"

int main(int ac, char **av)
{
	char *delim[] = {"\n", "\t", " "};
	char *str;
	char *buffer = NULL;
	size_t bufsize;
	int status;

	while (1)	
	{
		printf("#cisfun$ ");
		if (getline (&buffer, &bufsize, stdin) == -1)
		{
			if (feof(stdin))
				exit(EXIT_SUCCESS);
			else
			{
				perror("./shell");
				exit(0);
			}
		}
		str = strtok(buffer, *delim);
		av[0] = str;
		av[1] = NULL;
			
		if(fork() == 0)
		{
			if (execve(av[0], av, NULL) == -1)
			{
				perror("Error:");
				exit(0);
			}
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
		free(buffer);
		buffer = NULL;
	}	
	return (0);
}
