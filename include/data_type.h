/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:11:17 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/05/01 10:37:27 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_TYPE_H
# define DATA_TYPE_H

typedef enum e_type_kind {
	UNSETED,
	TYPE_INT,
	TYPE_PTR,
}	t_type_kind;

typedef struct s_type	t_data_type;

struct s_type
{
	t_type_kind	kind;
	t_data_type	*ptr_to;
};

int	size_of_kind(t_type_kind kind);

#endif
