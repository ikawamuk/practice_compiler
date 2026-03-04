/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:11:17 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 12:26:11 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_TYPE_H
# define DATA_TYPE_H

typedef enum e_type_kind {
	TYPE_INT
}	t_type_kind;

typedef struct s_type	t_data_type;

struct s_type
{
	t_type_kind	kind;
	t_data_type	*base;
};

#endif
