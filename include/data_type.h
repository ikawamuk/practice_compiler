/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:11:17 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/11 20:42:17 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_TYPE_H
# define DATA_TYPE_H

# include <stddef.h>

typedef enum e_type_kind {
	UNSETED,
	TYPE_INT,
	TYPE_PTR,
	TYPE_ARRAY
}	t_type_kind;

typedef struct s_type	t_data_type;

struct s_type
{
	t_type_kind	kind;
	t_data_type	*base;
	size_t		array_size;
};

int	size_of(t_data_type *data_type);

#endif
