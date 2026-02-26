/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:45:56 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/26 22:26:08 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "arena.h"
#include"tree.h"
#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

bool	is_expected(const char *op, t_token *token);
t_tree	*expr(t_token **token_p);
static t_tree	*expr_list(t_token **token_p);

/*
func_args   = "(" expr_list? ")"
*/
t_tree  *func_args(t_token **token_p)
{
	if (!is_expected("(", *token_p))
	{
		fprintf(stderr, "expected \'(\'\n");
		clear_arena();
		exit(EXIT_FAILURE);
	}
	*token_p = (*token_p)->next;
	if (is_expected(")", *token_p))
	{
		*token_p = (*token_p)->next;
		return (NULL);
	}
	t_tree	*node = expr_list(token_p);
	if (is_expected(")", *token_p))
	{
		*token_p = (*token_p)->next;
		return (node);
	}
	fprintf(stderr, "expected \')\'\n");
	clear_arena();
	exit(EXIT_FAILURE);
}

/*
expr_list	= (expr ("," expr)*)
*/
static t_tree	*expr_list(t_token **token_p)
{
	t_tree	*head = expr(token_p);
	t_tree  *cur = head;
	while (is_expected(",", *token_p))
	{
		*token_p = (*token_p)->next;
		cur->next = expr(token_p);
		cur = cur->next;
	}
	return (head);
}
