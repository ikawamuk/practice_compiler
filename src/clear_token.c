/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 22:59:48 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 04:04:53 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdlib.h>
#include <stdbool.h>

void	clear_token(t_token *cur)
{
	t_token	*next;

	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	return ;
}

bool	consume_op(t_token **list_p, char c)
{
	if ((*list_p)->str[0] != c)
		return (false);
	*list_p = (*list_p)->next;
	return (true);
}
