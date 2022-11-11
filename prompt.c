#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

char * _read_line(void)
{
	char *buffer = NULL;
	size_t bufsize;

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
	printf("%s", buffer);

	free(buffer);
	return (buffer);
}
