/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 23:03:43 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 00:00:34 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void			clear_token(t_token *cur);
static int		tokenize_recursive(char *str, t_token **list_p);
static t_token	*new_token(t_tk_type type, char *str);

int	tokenize(char *str, t_token **list_p)
{
	if (tokenize_recursize(str, list_p) != 0)
	{
		clear_token(*list_p);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	tokenize_recursive(char *str, t_token **list_p)
{
	t_tk_type	type;

	while (isspace(*str))
		str++;
	if (!*str)
		type = TK_EOF;
	else if (*str == '+' || *str == '-')
		type = TK_RESERVED;
	else if (isdigit(*str))
		type = TK_NUM;
	else
	{
		fprintf(stderr, "Ccc: error: invalid character '%c'\n", *str);
		return (EXIT_FAILURE);
	}
	*list_p = new_token(type, str);
	if (*list_p)
		return (EXIT_FAILURE);
	return (tokenize_recursive(str, (*list_p)->next));
}

static t_token	*new_token(t_tk_type type, char *str)
{
	t_token	*new;

	new = calloc(1, sizeof(t_token));
	if (!new)
		return (NULL);
	new->type = type;
	if (type == TK_NUM)
		new->data.val = strtol(str, &str, 10);
	else
		new->data.str = str;
	new->next = NULL;
	return (new);
}
