/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:11:41 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/05 22:14:10 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include "token.h"
#include "local_variable.h"
#include <stdlib.h>

t_var	*find_var(const t_token *token);
t_tree	*new_variable_leaf(t_var *var);
void	error_at(const char *location, const char *err_msg);
/*
variable
*/
t_tree	*variable(t_token **token_p)
{
	t_var	*var = find_var(*token_p);
	if (!var)
	{
		error_at((*token_p)->str, "use of undeclared identifier");
		clear_arena();
		exit(EXIT_FAILURE);
	}
	t_tree	*node = new_variable_leaf(var);
	*token_p = (*token_p)->next;
	return (node);
}
