#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * main - stat example
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    unsigned int i;
    struct stat st;
    char *get_path;
    size_t get_size;

    if (ac < 2)
    {
        printf("Usage: _which filename...\n");
        return (1);
    }
    i = 1;
    while (av[i])
    {
        printf("%s:", av[i]);
        if (stat(av[i], &st) == 0)
        {
		printf(" FOUND\n");
		get_size = st.st_size;
		get_path = getcwd(av[i], get_size);
		printf("Path is: %s\n", get_path);
        }
        else
        {
            printf(" NOT FOUND\n");
        }
        i++;
    }
    return (0);
}
