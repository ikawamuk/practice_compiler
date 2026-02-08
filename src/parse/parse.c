/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:05:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 16:49:44 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "arena.h"
#include "token.h"
#include <stdlib.h>

t_tree	*expr(t_token **token_p);

t_tree	*parse(t_token *token_list)
{
	t_tree	*ast = expr(&token_list);

	if (!ast)
	{
		clear_arena();
		exit(EXIT_FAILURE);
	}
	return (ast);
}
