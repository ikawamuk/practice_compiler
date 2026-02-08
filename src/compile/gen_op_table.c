/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 22:07:27 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 22:25:06 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gen_table.h"
#include <stdio.h>

void	generate_add(FILE *asm_file);
void	generate_sub(FILE *asm_file);
void	generate_mul(FILE *asm_file);
void	generate_div(FILE *asm_file);
void	generate_equal(FILE *asm_file);
void	generate_not_equal(FILE *asm_file);
void	generate_less_than(FILE *asm_file);
void	generate_less_equal(FILE *asm_file);

static const t_nd_gen	gen_op_table[] = {
	{ND_ADD, generate_add},
	{ND_SUB, generate_sub},
	{ND_MUL, generate_mul},
	{ND_DIV, generate_div},
	{ND_EQ, generate_equal},
	{ND_NE, generate_not_equal},
	{ND_LT, generate_less_than},
	{ND_LE, generate_less_equal}
};

void	(*get_op_generator(t_nd_type type))(FILE *)
{
	for (size_t i = 0; i < sizeof(gen_op_table)/sizeof(t_nd_gen); i++)
	{
		if (type == gen_op_table[i].type)
			return (gen_op_table[i].gen);
	}
	return (NULL);
}
