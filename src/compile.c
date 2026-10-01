/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 02:25:31 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/02 02:40:00 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compilation.h"
#include "arena.h"
#include <stdlib.h>

int	read_source(t_compilation *ctx, const char *src_file_path);
int	tokenize(t_compilation *ctx);
int	parse(t_compilation *ctx);
int	code_gen(t_compilation *ctx);
int	assemble(t_compilation *ctx);
int	link(t_compilation *ctx, const char **obj_file_names);

static void	clean_compilation(t_compilation *ctx);

int	compile(const char **file_names) {
	t_compilation	compile_ctx;

	if (read_source(&compile_ctx, file_names[0]) < 0)
		return (clean_compilation(&compile_ctx), -1);
	if (tokenize(&compile_ctx) < 0)
		return (clean_compilation(&compile_ctx), -1);
	if (parse(&compile_ctx) < 0)
		return (clean_compilation(&compile_ctx), -1);
	if (code_gen(&compile_ctx) < 0)
		return (clean_compilation(&compile_ctx), -1);
	clear_arena();
	if (assemble(&compile_ctx) < 0)
		return (clean_compilation(&compile_ctx), -1);
	if (link(&compile_ctx, file_names + 1) < 0)
		return (clean_compilation(&compile_ctx), -1);
	return (clean_compilation(&compile_ctx), 0);
}

static void	clean_compilation(t_compilation *ctx) {
	switch (ctx->phase)
	{
		case SOURCE_CONTENT:
		case TOKEN_LIST:
		case AST:
			clear_arena();
			break ;
		case ASM_FILE_NAME:
			free(ctx->asm_file_name);
			break ;
		case OBJ_FILE_NAME:
			free(ctx->obj_file_name);
			break ;
		default:
			break ;
	}
}
