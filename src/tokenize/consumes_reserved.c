/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consumes_reserved.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:36:21 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/12 16:35:33 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdbool.h>
#include <string.h>

bool		is_identifier_char(char c);
static bool	consumes_return(t_token *new, const char **str_p);

bool	consumes_reserved(t_token *new, const char **str_p)
{
	if (consumes_return(new, str_p))
		return (true);
	return (false);
}

static bool	consumes_return(t_token *new, const char **str_p)
{
	if (!memcmp(*str_p, "return", 6) && !is_identifier_char((*str_p)[6]))
	{
		*str_p += 6;
		new->len = 6;
		new->type = TK_RETURN;
		return (true);
	}
	return (false);
}
