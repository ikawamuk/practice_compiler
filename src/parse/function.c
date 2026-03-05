/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 02:01:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/05 23:00:51 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "function.h"
#include "arena.h"
#include "local_variable.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void			error_at(const char *location, const char *err_msg);
char			*dup_token_str(t_token *token);
t_function		*new_function(t_function func_data);
bool			is_expected(const char *op, t_token *token);
t_tree			*block(t_token **token_p);
t_var_list		*get_var_list(void);
int				get_var_list_size(void);
void			clear_list_stack(void);
static t_tree	*args_declaration(t_token **token_p);
t_data_type		*data_kw(t_token *token);


#include <stdio.h>
/*
function	=	ident args_declaration block // funcn_name(arg1, arg2){ ... ;  ...;}
*/
t_function	*function(t_token **token_p)
{
	if ((*token_p)->type != TK_RESERVED)
	{
		error_at((*token_p)->str, "expected function declaration\n");
		clear_arena();
		exit(EXIT_FAILURE);
	}
	t_function	func_data = {};
	func_data.data_type = data_kw(*token_p);
	*token_p = (*token_p)->next;
	func_data.name = dup_token_str(*token_p);
	*token_p = (*token_p)->next;
	args_declaration(token_p);
	func_data.argc = get_var_list_size();
	func_data.body = block(token_p);
	func_data.locals = get_var_list();
	clear_list_stack();
	t_function *function = new_function(func_data);
	return (function);
}



static t_tree	*params(t_token **token_p);
/*
args_declaration   = "(" params? ")"
*/
static t_tree	*args_declaration(t_token **token_p)
{
	if (!is_expected("(", *token_p))
	{
		error_at((*token_p)->str, "expected \'(\'\n");
		clear_arena();
		exit(EXIT_FAILURE);
	}
	*token_p = (*token_p)->next;
	if (is_expected(")", *token_p))
	{
		*token_p = (*token_p)->next;
		return (NULL);
	}
	t_tree	*node = params(token_p);
	if (is_expected(")", *token_p))
	{
		*token_p = (*token_p)->next;
		return (node);
	}
	error_at((*token_p)->str, "expected \')\'\n");
	clear_arena();
	exit(EXIT_FAILURE);
}

t_tree	*var_declar(t_token **token_p);

/*
params	= (variable ("," variable)*)
*/
static t_tree	*params(t_token **token_p)
{
	t_tree	*head = var_declar(token_p);
	t_tree  *cur = head;
	while (is_expected(",", *token_p))
	{
		*token_p = (*token_p)->next;
		cur->next = var_declar(token_p);
		cur = cur->next;
	}
	return (head);
}


