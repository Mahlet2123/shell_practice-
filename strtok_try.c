#include <stdio.h>
#include <string.h>

int main(int __attribute__((__unused__))ac, char **av)
{
	char *delim = " ";
	char *word;

	word = strtok(av[1], delim);

	while (word != NULL)
	{
		printf("%s\n", word);
		word = strtok(NULL, delim);
	}
	return (0);
}
