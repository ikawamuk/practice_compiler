/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 03:26:29 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 22:29:31 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "arena.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void		generate_num(FILE *assem_src, const t_tree *node);
void		generate_negative(FILE *assem_src, const t_tree *node);
void		generate_address(FILE *assem_src, const t_tree *node);
void		generate_dereference(FILE *assem_src, const t_tree *node);
void		generate_assign(FILE *assem_src, const t_tree *node);
void		generate_local_variable(FILE *assem_src, const t_tree *node);
void		generate_expr_stmt(FILE *assem_src, const t_tree *node);
void		generate_return(FILE *assem_src, const t_tree *node);
void		generate_if(FILE *assem_src, const t_tree *node);
void		generate_while(FILE *assem_src, const t_tree *node);
void		generate_block(FILE *assem_src, const t_tree *node);
void		generate_operator(FILE *assem_src, const t_tree *node);
void		generate_func_call(FILE *assem_src, const t_tree *node);
static void	generate_decalrtion(FILE *assem_src, const t_tree *node);
static void	(*get_generator(t_nd_type type))(FILE *, const t_tree *);
static bool	is_operator(t_nd_type type);

struct s_nd_gen
{
	t_nd_type	type;
	void		(*gen)(FILE *, const t_tree *);
};

static const struct s_nd_gen	gen_table[] = {
	{ND_NUM, generate_num},
	{ND_NEG, generate_negative},
	{ND_ADDRESS, generate_address},
	{ND_DEREFER, generate_dereference},
	{ND_ASSIGN, generate_assign},
	{ND_LVAR, generate_local_variable},
	{ND_EXPR_STMT, generate_expr_stmt},
	{ND_RETURN, generate_return},
	{ND_IF, generate_if},
	{ND_WHILE, generate_while},
	{ND_BLOCK, generate_block},
	{ND_FUNC_CALL, generate_func_call},
	{ND_DECLAR, generate_decalrtion}
};

void	generate(FILE *assem_src, const t_tree *node)
{
	if (!node)
		return ;
	if (is_operator(node->node_type))
	{
		generate_operator(assem_src, node);
		return ;
	}
	get_generator(node->node_type)(assem_src, node);
}

static void	(*get_generator(t_nd_type type))(FILE *, const t_tree *)
{
	for (size_t i = 0; i < sizeof(gen_table)/sizeof(*gen_table); i++)
	{
		if (type == gen_table[i].type)
			return (gen_table[i].gen);
	}
	return (NULL);
}

static bool	is_operator(t_nd_type type)
{
	return (ND_ADD <= type && type <= ND_LE);
}

static void	generate_decalrtion(FILE *assem_src, const t_tree *node)
{
	(void)assem_src;
	(void)node;
}
