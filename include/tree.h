/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 02:54:13 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/12 18:00:12 by ikawamuk         ###   ########.fr       */
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
	t_tree		*childlen[4];
	// num
	int			val;
	// local variable
	int			offset;
};

// return
# define child childlen[0]
// operator
# define lhs childlen[0]
# define rhs childlen[1]
// if, while
# define cond childlen[0]
# define then childlen[1]
# define els childlen[2]


#endif
