#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *buffer = NULL;
	size_t bufsize;

	printf("$ ");
	getline (&buffer, &bufsize, stdin);
	printf("%s", buffer);

	free(buffer);
	return (0);
}
