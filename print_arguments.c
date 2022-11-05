#include <stdio.h>
#include <stdlib.h>

int main(int __attribute__((__unused__))ac, char **av)
{
	int i = 0;

	for (i = 1; av[i] != NULL; i++)
	{
		printf ("%s\n", av[i]);
	}
	return (0);
}
