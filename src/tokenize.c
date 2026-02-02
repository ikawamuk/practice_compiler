/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 23:03:43 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 12:34:34 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static t_tk_type	match_type(char *str);
void				clear_token(t_token *cur);
static int			tokenize_recursive(char *str, t_token **list_p);
static t_token		*new_token(t_tk_type type, char **str_p);
// static char		*dup_token(char *str);

t_token *tokenize(char *str)
{
	t_token *list;

	list = NULL;
	if (tokenize_recursive(str, &list) != 0)
	{
		clear_token(list);
		return (NULL);
	}
	return (list);
}

static int	tokenize_recursive(char *str, t_token **list_p)
{
	t_tk_type	type;

	while (isspace(*str))
		str++;
	type = match_type(str);
	if (type == TK_ERROR)
	{
		fprintf(stderr, "Ccc: error: invalid character '%c'\n", *str);
		return (EXIT_FAILURE);
	}
	*list_p = new_token(type, &str);
	if (!*list_p)
		return (EXIT_FAILURE);
	if (type == TK_EOF)
		return (EXIT_SUCCESS);
	return (tokenize_recursive(str, &(*list_p)->next));
}

static t_tk_type	match_type(char *str)
{
	if (!*str)
		return (TK_EOF);
	else if (*str == '+'
			|| *str == '-'
			|| *str == '*'
			|| *str == '/'
			|| *str == '('
			|| *str == ')')
		return (TK_RESERVED);
	else if (isdigit(*str))
		return (TK_NUM);
	return (TK_ERROR);
}

static t_token	*new_token(t_tk_type type, char **str_p)
{
	t_token	*new;

	new = calloc(1, sizeof(t_token));
	if (!new)
		return (NULL);
	new->type = type;
	new->str = *str_p;
	if (type == TK_NUM)
		new->val = strtol(*str_p, str_p, 10);
	else
		// while (**str_p && !isspace(**str_p) && !isdigit((**str_p)))
			(*str_p)++;
	new->next = NULL;
	return (new);
}

// static char	*dup_token(char *str)
// {
// 	char	*token;
// 	size_t	len;

// 	len = 0;
// 	while (str[len] && !isspace(str[len]))
// 		len++;
// 	token = calloc(len + 1, sizeof(char));
// 	if (!token)
// 		return (NULL);
// 	return (strncpy(token, str, len));
// }
