/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_kw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:47:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/05 21:51:24 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_type.h"
#include "token.h"
#include <stdbool.h>

bool		is_expected(const char *op, t_token *token);
t_data_type	*new_int(void);

t_data_type	*data_kw(t_token *token)
{
	if (is_expected("int", token))
		return (new_int());
	return (NULL);
}
