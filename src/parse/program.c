/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:40:38 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 21:28:55 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "tree.h"
#include "token.h"
#include "arena.h"
#include <stdio.h>

static t_tree	*create_ast(t_token **token_p);
t_tree			*stmt(t_token **token_p);
t_lvar			*get_list(void);
void			clear_list_stack(void);

t_program	*program(t_token **token_p)
{
	t_program	*prog = aalloc(sizeof(t_program));
	if (!prog)
		return (NULL);
	prog->ast = create_ast(token_p);
	prog->var_list = get_list();
	clear_list_stack();
	return (prog);
}

void	print_ast(t_tree *ast);

/*
ast	= stmt*
*/
static t_tree	*create_ast(t_token **token_p)
{
	t_tree	dummy_head = {0};
	t_tree	*cur = &dummy_head;

	while ((*token_p)->type != TK_EOF)
	{
		cur->next = stmt(token_p);
		cur = cur->next;
	}
	return (dummy_head.next);
}
