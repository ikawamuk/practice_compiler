
#include <stdlib.h>
#include <stdio.h>

int run_command(char *const args[]);
static char	**make_command(char *obj_name, char **extra_objs);
static int	count_str_arr(char **strarr);


int    link(char *obj_name, char **extra_objs)
{
	char	**args = make_command(obj_name, extra_objs);
	if (!args)
	{
		perror("malloc");
		return (-1);
	}
	if (run_command(args) != 0)
	{
		free((char *)obj_name);
		fprintf(stderr, "Error: Failed to link\n");
		return (-1);
	}
	free(args);
	printf("succeeded generate exe file\n");
	return (0);
}

static char	**make_command(char *obj_name, char **extra_objs)
{
	int		extra_cnt = count_str_arr(extra_objs);
	char	**args = malloc(sizeof(char *) * (extra_cnt + 5));
	if (!args)
		return (NULL);
	int	i = 0;
	args[i++] = "gcc";
	args[i++] = obj_name;
	int	j = 0;
	while (j < extra_cnt)
		args[i++] = extra_objs[j++];
	// args[i++] = "-o";
	// args[i++] = "b.out";
	args[i] = NULL;
	return (args);
}

static int	count_str_arr(char **strarr)
{
	int	cnt = 0;
	while (strarr && strarr[cnt])
		cnt++;
	return  (cnt);
}
