/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consumes_reserved.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:36:21 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 21:56:11 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdbool.h>
#include <string.h>

bool		is_identifier_char(char c);
static bool	consumes_key_word(t_token *new, const char **str_p);
static bool	consumes_operator(t_token *new, const char **str_p);
static bool	consumes_signle_letter_punctuator(t_token *new, const char **str_p);

bool	consumes_reserved(t_token *new, const char **str_p)
{
	if (consumes_key_word(new, str_p))
		return (true);
	if (consumes_operator(new, str_p))
		return (true);
	if (consumes_signle_letter_punctuator(new, str_p))
		return (true);
	return (false);
}

static bool	consumes_signle_letter_punctuator(t_token *new, const char **str_p)
{
	if (strchr("+-*/%()<>;={},&", **str_p))
	{
		*str_p += 1;
		new->len = 1;
		new->type = TK_RESERVED;
		return (true);
	}
	return (false);
}

static bool	consumes_operator(t_token *new, const char **str_p)
{
	const char	*operators[] = {
		"==", "!=", "<=", ">=", "+=", "-="
	};
	for (size_t i = 0; i < sizeof(operators) / sizeof(*operators); i++)
	{
		size_t	len = strlen(operators[i]);
		if (!memcmp(*str_p, operators[i], len))
		{
			*str_p += len;
			new->len = (int)len;
			new->type = TK_RESERVED;
			return (true);
		}
	}
	return (false);
}

static bool	consumes_key_word(t_token *new, const char **str_p)
{
	const char	*key_words[] = {
		"return", "if", "else", "while", "int"
	};
	for (size_t i = 0; i < sizeof(key_words) / sizeof(*key_words); i++)
	{
		size_t	len = strlen(key_words[i]);
		if (!memcmp(*str_p, key_words[i], len) && !is_identifier_char((*str_p)[len]))
		{
			*str_p += len;
			new->len = (int)len;
			new->type = TK_RESERVED;
			return (true);
		}
	}
	return (false);
}
