/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/03 18:42:32 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include <stdlib.h>
#include <stdio.h>

char	*read_in_bulk(t_arena *arena, FILE *fp);
t_token *tokenize(t_arena *arena, const char *str);
t_tree	*parse(t_arena *arena, t_token *token_list);
int		compile(t_tree *ast);

int	main(int argc, char *argv[])
{
	int		exit_status;
	t_ctx	ctx = {0};

	if (argc < 2)
		return (EXIT_FAILURE);
	// file name -> file content
	ctx.file_path = argv[1];
	ctx.fp = fopen(ctx.file_path, "r");
	if (!ctx.fp)
		return (EXIT_FAILURE);
	ctx.file_content = read_in_bulk(&ctx.arena, ctx.fp);
	fclose(ctx.fp);
	if (!ctx.file_content)
		return (clear_arena(&ctx.arena), EXIT_FAILURE);
	// file content -> token list
	ctx.token_list = tokenize(&ctx.arena, ctx.file_content);
	if (!ctx.token_list)
		return (clear_arena(&ctx.arena), EXIT_FAILURE);
	// token list -> ast
	ctx.ast = parse(&ctx.arena, ctx.token_list);
	if (!ctx.ast)
		return (clear_arena(&ctx.arena), EXIT_FAILURE);
	exit_status = compile(ctx.ast);
	clear_arena(&ctx.arena);
	return (EXIT_SUCCESS);
}
