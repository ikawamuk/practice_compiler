/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consumes_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:33:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/12 16:34:21 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdbool.h>
#include <string.h>

static bool	consumes_operator1(t_token *new, const char **str_p);
static bool	consumes_operator2(t_token *new, const char **str_p);

bool	consumes_operator(t_token *new, const char **str_p)
{
	if (consumes_operator2(new, str_p))
		return (true);
	if (consumes_operator1(new, str_p))
		return (true);
	return (false);
}

static bool	consumes_operator1(t_token *new, const char **str_p)
{
	if (strchr("+-*/()<>;={}", **str_p))
	{
		*str_p += 1;
		new->len = 1;
		new->type = TK_OPERATOR;
		return (true);
	}
	return (false);
}

static bool	consumes_operator2(t_token *new, const char **str_p)
{
	if (!memcmp(*str_p, "==", 2) || !memcmp(*str_p, "!=", 2)
	|| !memcmp(*str_p, "<=", 2) || !memcmp(*str_p, ">=", 2))
	{
		*str_p += 2;
		new->len = 2;
		new->type = TK_OPERATOR;
		return (true);
	}
	return (false);
}