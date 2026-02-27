/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 02:01:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 07:42:02 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include "arena.h"
#include "local_variable.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void				*xaalloc(size_t size);
bool				is_expected(const char *op, t_token *token);
t_tree				*block(t_token **token_p);
t_lvar				*get_var_list(void);
void				clear_list_stack(void);
static t_tree		*args_declaration(t_token **token_p);
static t_function	*new_function(const char *name, t_tree *body, t_lvar *var_list);
static char			*dup_token_str(t_token *token);

/*
function	=	ident args_declaration block
*/
t_function	*function(t_token **token_p)
{
	if ((*token_p)->type != TK_IDENT)
	{
		fprintf(stderr, "expected function declaration\n");
		clear_arena();
		exit(EXIT_FAILURE);
	}
	char	*name = dup_token_str(*token_p);
	*token_p = (*token_p)->next;
	args_declaration(token_p);
	t_tree *body = block(token_p);
	t_function *function = new_function(name, body, get_var_list());
	clear_list_stack();
	return (function);
}

static char	*dup_token_str(t_token *token)
{
	char	*str = xaalloc(token->len + 1);
	strncpy(str, token->str, token->len);
	return (str);
}

static t_function	*new_function(const char *name, t_tree *body, t_lvar *var_list)
{
	t_function	*function = xaalloc(sizeof(t_function));
	function->name = name;
	function->node = body;
	function->var_list = var_list;
	return (function);
}

static t_tree	*variable_list(t_token **token_p);
/*
args_declaration   = "(" variable_list? ")"
*/
static t_tree  *args_declaration(t_token **token_p)
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
	t_tree	*node = variable_list(token_p);
	if (is_expected(")", *token_p))
	{
		*token_p = (*token_p)->next;
		return (node);
	}
	fprintf(stderr, "expected \')\'\n");
	clear_arena();
	exit(EXIT_FAILURE);
}

t_tree	*variable(t_token **token_p);

/*
variable_list	= (variable ("," variable)*)
*/
static t_tree	*variable_list(t_token **token_p)
{
	t_tree	*head = variable(token_p);
	t_tree  *cur = head;
	while (is_expected(",", *token_p))
	{
		*token_p = (*token_p)->next;
		cur->next = variable(token_p);
		cur = cur->next;
	}
	return (head);
}


