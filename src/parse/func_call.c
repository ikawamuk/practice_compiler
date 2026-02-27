/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_call.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 05:34:16 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 08:48:38 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include "token.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


char	*dup_token_str(t_token *token);
bool	is_expected(const char *op, t_token *token);
t_tree	*new_func_call_leaf(const char *func_name, t_tree *args);
t_tree  *func_args(t_token **token_p);

/*
func_call	=	ident func_args
*/
t_tree	*func_call(t_token **token_p)
{
	char	*func_name = dup_token_str(*token_p);
	*token_p = (*token_p)->next;
	return (new_func_call_leaf(func_name, func_args(token_p)));
}
