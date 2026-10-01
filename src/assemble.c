/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:32 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/02 02:36:27 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compilation.h"
#include "ccc_define.h"
#include "arena.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

char		*replace_file_extention(const char *file_name, const char *new_extention);
static char	*make_obj_name(const char *assem_src_fd_name);
int 		run_command(char *const args[]);


int	assemble(t_compilation *ctx)
{
	char	*obj_name = make_obj_name(ctx->asm_file_name);
	if (!obj_name)
		return (-1);
	char	*args[] = {"gcc", "-c", (char *)ctx->asm_file_name, "-o", obj_name, NULL};
	if (run_command(args) != 0)
	{
		free(obj_name);
		dprintf(2, "Error: Failed to assemble %s\n", ctx->asm_file_name);
		return (-1);
	}
	printf("Object file generated: %s\n", obj_name);
	ctx->obj_file_name = obj_name;
	ctx->phase = OBJ_FILE_NAME;
	return (0);
}

int run_command(char *const args[])
{
	pid_t pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		execvp(args[0], args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	int status;
	if (waitpid(pid, &status, 0) == -1)
		return (-1);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (-1);
}

static char	*make_obj_name(const char *assem_src_fd_name)
{
	return (replace_file_extention(assem_src_fd_name, ".o"));
}
