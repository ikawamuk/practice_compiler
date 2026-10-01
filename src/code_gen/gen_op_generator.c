/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_op_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 22:07:27 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/05/01 10:19:20 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate_add(FILE *, const t_tree *node);
void	generate_sub(FILE *, const t_tree *node);
void	generate_mul(FILE *, const t_tree *node);
void	generate_div(FILE *, const t_tree *node);
void	generate_mod(FILE *, const t_tree *node);
void	generate_equal(FILE *, const t_tree *node);
void	generate_not_equal(FILE *, const t_tree *node);
void	generate_less_than(FILE *, const t_tree *node);
void	generate_less_equal(FILE *, const t_tree *node);

struct s_op_gen
{
	t_nd_type	type;
	void		(*gen)(FILE *, const t_tree *);
};

static const struct s_op_gen	gen_op_table[] = {
	{ND_ADD, generate_add},
	{ND_SUB, generate_sub},
	{ND_MUL, generate_mul},
	{ND_DIV, generate_div},
	{ND_MOD, generate_mod},
	{ND_EQ, generate_equal},
	{ND_NE, generate_not_equal},
	{ND_LT, generate_less_than},
	{ND_LE, generate_less_equal}
};

void	(*get_op_generator(t_nd_type type))(FILE *, const t_tree *node)
{
	for (size_t i = 0; i < sizeof(gen_op_table)/sizeof(*gen_op_table); i++)
	{
		if (type == gen_op_table[i].type)
			return (gen_op_table[i].gen);
	}
	return (NULL);
}
