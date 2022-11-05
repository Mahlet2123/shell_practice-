#include <stdio.h>
#include <unistd.h>

int main (void)
{
	pid_t pid;

	printf("befor fork was called\n");
	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		return (-1);
	}
	printf("after fork was called\n");
	return (0);
}
