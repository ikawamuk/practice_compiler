/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:40:38 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 18:46:33 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "tree.h"
#include "token.h"
#include "arena.h"
#include <stdio.h>

t_tree	*stmt(t_token **token_p);
t_lvar	*get_list(void);
void	clear_list_stack(void);

t_program	*program(t_token **token_p)
{
	t_tree	dummy_head = {0};
	t_tree	*cur = &dummy_head;

	while ((*token_p)->type != TK_EOF)
	{
		cur->next = stmt(token_p);
		cur = cur->next;
	}
	t_program	*prog = aalloc(sizeof(t_program));
	if (!prog)
		return (NULL);
	prog->ast = dummy_head.next;
	prog->var_list = get_list();
	clear_list_stack();
	return (prog);
}
