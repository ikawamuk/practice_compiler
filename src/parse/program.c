/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:40:38 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 20:40:30 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "token.h"
#include <stdio.h>
t_tree	*stmt(t_token **token_p);

t_tree	*program(t_token **token_p)
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
