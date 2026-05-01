/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 19:44:40 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/05/01 10:43:10 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_type.h"
#include <token.h>
#include <stddef.h>
#include <stdbool.h>

void		*xaalloc(size_t size);
bool		is_expected(const char *op, t_token *token);

t_data_type	*new_data_type(t_type_kind kind, t_data_type *ptr_to)
{
	t_data_type	*new = xaalloc(sizeof(t_data_type));
	new->kind = kind;
	new->ptr_to = ptr_to;
	return (new);
}

t_data_type	*new_int(void)
{
	return (new_data_type(TYPE_INT, NULL));
}

t_data_type	*new_ptr_to(t_data_type *ptr_to)
{
	return (new_data_type(TYPE_PTR, ptr_to));
}

int	size_of_kind(t_type_kind kind)
{
	switch (kind)
	{
		case TYPE_INT:
			return (4);
		case TYPE_PTR:
			return (8);
		default:
			return (1);
	}
}
