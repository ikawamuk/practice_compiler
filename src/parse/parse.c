/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:05:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/02 02:39:14 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compilation.h"
#include "tree.h"
#include "arena.h"
#include "token.h"
#include "function.h"
#include <stdlib.h>
#include <stdio.h>

t_func_list	*program(t_token **token_p);

int	parse(t_compilation *ctx)
{
	t_func_list	*prog = program(&ctx->token_list);
	ctx->function_list = prog;
	ctx->phase = AST;
	return (0);
}
