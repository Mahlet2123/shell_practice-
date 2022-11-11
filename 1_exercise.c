#include "shell.h"

int main()
{
	char *av[] = {"fork", NULL};
	int i;

	for(i = 0; i < 5; i++)
	{
		if(fork() == 0)
		{
			printf("[c]pid %d from [p]pid %d\n",getpid(),getppid());			if (execve(av[0], av, NULL) == -1)
				perror("Error:");
			exit(0);
		}
	}
	while (wait(NULL) != -1 || errno != ECHILD)
	{
		printf("waited for a chiled to finish\n");
	}

	return (0);
}
