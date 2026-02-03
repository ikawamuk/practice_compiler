/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_expect_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:17:26 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/03 16:21:49 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdbool.h>
#include <string.h>

bool	is_expected_op(const char *op, t_token *token)
{
	return (token->type == TK_RESERVED
	&& strlen(op) == token->len
	&& !memcmp(op, token->str, token->len));
}
