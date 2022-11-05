#include "shell.h"

int main()
{
	/*char *av[] = {"/bin/ls", "-l", "/tmp", NULL};*/

	int id, id1;

	id = fork();

	while (id == 0)
	{
		id1 = fork();
	}
	
/**
*	for (i = 0; i < (n - 2) && i >= 0; i++)
*	{
*		id[i] = fork();
*		if (id[i] == 0)
*			id[i + 1] = fork();
*	}
*/
	printf("HI THERE\n");
/**	if (execve(av[0], av, NULL) == -1)
*		perror("Error:");
*	while (x != -1 || errno != ECHILD)
*		printf("waited all the childeren");
*/
	return (0);
}
