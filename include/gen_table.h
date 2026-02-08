/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_table.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 22:10:32 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 22:21:12 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEN_TABLE_H
# define GEN_TABLE_H

#include "tree.h"
#include <stdio.h>

typedef struct s_nd_gen
{
	t_nd_type	type;
	void		(*gen)(FILE *asm_file);
}	t_nd_gen;

void	(*get_generator(t_nd_type type))(FILE *);

#endif
