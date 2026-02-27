/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:40:38 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 06:45:21 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

t_function	*function(t_token **token_p);

/*
program	=	function*
*/
t_function	*program(t_token **token_p)
{
	t_function	head;
	t_function	*cur = &head;

	cur->next = NULL;
	while ((*token_p)->type != TK_EOF)
	{
		cur->next = function(token_p);
		if (!cur->next)
			return (NULL);
		cur = cur->next;
	}
	return (cur->next);
}
