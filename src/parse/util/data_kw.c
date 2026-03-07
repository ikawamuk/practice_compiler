/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_kw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:47:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 01:08:57 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_type.h"
#include "token.h"
#include <stdbool.h>

static char	*data_type_reserved[] = {
	"int"
};

bool		is_expected(const char *op, t_token *token);
t_data_type	*new_int(void);
t_data_type	*new_ptr_to(t_data_type *ptr_to);

t_data_type	*data_type_kw(t_token **token_p)
{
	t_data_type	*dt_type;

	if (is_expected("int", *token_p))
	{
		*token_p = (*token_p)->next;
		dt_type = new_int();
		while (is_expected("*", *token_p))
		{
			*token_p = (*token_p)->next;
			dt_type = new_ptr_to(dt_type);
		}
		return (dt_type);
	}
	return (NULL);
}

bool	is_data_type_reserved(t_token *token)
{
	for (size_t i = 0; i < sizeof(data_type_reserved) / sizeof(data_type_reserved[0]); i++)
		if (is_expected(data_type_reserved[i], token))
			return (true);
	return (false);
}
