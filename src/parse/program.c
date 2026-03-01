/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:40:38 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/01 19:42:51 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include "token.h"
#include <stdio.h>

void		*xaalloc(size_t size);
t_function	*function(t_token **token_p);

void	print_var_list(t_var_list *list);
/*
program	=	function*
*/
t_func_list	*program(t_token **token_p)
{
	t_func_list	head;
	t_func_list	*cur = &head;

	cur->next = NULL;
	while ((*token_p)->type != TK_EOF)
	{
		cur->next = xaalloc(sizeof(t_func_list));
		cur->next->func = function(token_p);
		cur = cur->next;
		// printf("argc: %d\n", cur->func->argc);
		// printf("[locals]\n");
		// print_var_list(cur->func->locals);
	}
	return (head.next);
}
