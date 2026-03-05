/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_token_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 08:30:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 08:48:13 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <string.h>

void	*xaalloc(size_t size);

char	*dup_token_str(const t_token *token)
{
	char	*str = xaalloc(token->len + 1);
	memcpy(str, token->str, token->len);
	str[token->len] = '\0';
	return (str);
}
