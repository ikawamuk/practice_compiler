/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 19:44:40 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/05 21:47:11 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_type.h"
#include <stddef.h>

t_data_type	*new_data_type(t_type_kind kind, t_data_type *base)
{
	t_data_type	*new = xaalloc(sizeof(t_data_type));
	new->kind = kind;
	new->base = base;
	return (new);
}

t_data_type	*new_int(void)
{
	return (new_data_type(TYPE_INT, NULL));
}

// t_data_type	*new_ptr_to(t_data_type *base)
// {
// 	return (new_data_type(TYPE_PTR, base));
// }
