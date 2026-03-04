/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:11:17 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 12:13:34 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

typedef enum {
	TYPE_INT
}	t_type_kind;

typedef struct s_type	t_data_type;

struct s_type
{
	t_type_kind	kind;
	t_data_type	*base;
};

#endif
