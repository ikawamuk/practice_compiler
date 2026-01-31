/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 22:59:48 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 01:56:27 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdlib.h>

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
