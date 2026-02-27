/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_token_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 08:30:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 08:30:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <string.h>

void	*xaalloc(size_t size);

char	*dup_token_str(t_token *token)
{
	char	*str = xaalloc(token->len + 1);
	strncpy(str, token->str, token->len);
	return (str);
}
