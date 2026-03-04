/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_type_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:35:20 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 12:35:37 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_type.h"
#include <stddef.h>

t_data_type	set_data_type_int(void)
{
	t_data_type	d_type;

	d_type.kind = TYPE_INT;
	d_type.base = NULL;
	return (d_type);
}
