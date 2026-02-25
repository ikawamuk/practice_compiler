
#include <stdlib.h>
#include <stdio.h>

int run_command(char *const args[]);

int    link(const char *obj_name, char **extra_objs)
{
    (void)extra_objs;
    char	*args[] = {"gcc", (char *)obj_name, "-o", "b.out", NULL};
	if (run_command(args) != 0)
	{
		free((char *)obj_name);
		fprintf(stderr, "Error: Failed to link\n");
		return (-1);
	}
    printf("succeeded generate exe file\n");
    return (0);
}
