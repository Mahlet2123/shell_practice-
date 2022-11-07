#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	_read_line();
	return(0);
}

char * _read_line(void)
{
	char *buffer = NULL;
	size_t bufsize;

	printf("$ ");
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
