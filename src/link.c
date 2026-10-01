/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 02:36:47 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/02 02:40:50 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compilation.h"
#include <stdlib.h>
#include <stdio.h>

int run_command(char *const args[]);
static char	**make_command(char *obj_name, const char **extra_objs);
static int	count_str_arr(const char **strarr);

int	link(t_compilation *ctx, const char **obj_file_names)
{
	char	**args = make_command(ctx->obj_file_name, obj_file_names);
	if (!args)
	{
		perror("malloc");
		return (-1);
	}
	if (run_command(args) != 0)
	{
		dprintf(2, "Error: Failed to link\n");
		return (-1);
	}
	free(args);
	printf("succeeded generate exe file\n");
	return (0);
}

static char	**make_command(char *obj_name, const char **extra_objs)
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
		args[i++] = (char *)extra_objs[j++];
	// args[i++] = "-o";
	// args[i++] = "b.out";
	args[i] = NULL;
	return (args);
}

static int	count_str_arr(const char **strarr)
{
	int	cnt = 0;
	while (strarr && strarr[cnt])
		cnt++;
	return  (cnt);
}
