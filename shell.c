#include "shell.h"

int main(int ac, char **av)
{
	char *str;
	char *buffer = NULL;
	size_t bufsize;
	int status;

	while (1)	
	{
		if(fork() == 0)
		{
			printf("#cisfun$ ");
			if (getline (&buffer, &bufsize, stdin) == -1)
			{
				if (feof(stdin))
					exit(EXIT_SUCCESS);
				else
				{
					perror("ERROR");
					exit(0);
				}
			}

			str = strtok(buffer, "\n ");
			av[0] = str;
			/**av[1] = strtok(NULL, "\n "); */
			
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
