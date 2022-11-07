#include <stdio.h>
#include <string.h>

int main(int __attribute__((__unused__))ac, char **av)
{
	_parse();
	return (0);
}

char *_parse(char *str, char *delim)
{
	char *delim = " ";
	char *token;

	token = strtok(av[1], delim);

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}
	return (token);
}
