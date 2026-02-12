/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 02:54:13 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/12 16:13:47 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

typedef enum {
	ND_NUM,
	ND_ADD, // +
	ND_SUB, // -
	ND_MUL, // *
	ND_DIV, // /
	ND_EQ, // ==
	ND_NE, // !=
	ND_LT, // <
	ND_LE, // <=
	ND_ASSIGN, // = 
	ND_LVAR, // local variable
	ND_RETURN
}	t_nd_type;

typedef struct s_tree	t_tree;

struct s_tree
{
	t_nd_type	type;
	t_tree		*next;
	// operator
	t_tree		*rhs;
	t_tree		*lhs;
	// num
	int			val;
	// local variable
	int			offset;
	// if, while
	
};

#endif
