/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 19:44:40 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/11 20:48:16 by ikawamuk         ###   ########.fr       */
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
	new->base = ptr_to;
	return (new);
}

t_data_type	*new_int(void)
{
	t_data_type	*new = xaalloc(sizeof(t_data_type));
	new->kind = TYPE_INT;
	new->base = NULL;
	new->array_size = 0;
	return (new);
}

t_data_type	*new_ptr_to(t_data_type *ptr_to)
{
	t_data_type	*new = xaalloc(sizeof(t_data_type));
	new->kind = TYPE_PTR;
	new->base = ptr_to;
	new->array_size = 0;
	return (new);
}

t_data_type	*new_array_of(t_data_type *array_of, int size)
{
	t_data_type	*new = xaalloc(sizeof(t_data_type));
	new->kind = TYPE_PTR;
	new->base = array_of;
	new->array_size = size;
	return (new);
}

int	size_of(t_data_type *data_type)
{
	switch (data_type->kind)
	{
		case TYPE_INT:
			return (4);
		case TYPE_PTR:
			return (8);
		case TYPE_ARRAY:
			return (size_of(data_type->base) * data_type->array_size);
		default:
			return (1);
	}
}
