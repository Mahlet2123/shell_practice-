#include <stdio.h>

int main(int ac, char **av, char **env)
{
	extern char **environ;

	printf("%p", env);
	printf("\n%p\n", environ);
}
