/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 02:54:13 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/05 22:49:00 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include "local_variable.h"
# include "data_type.h"

typedef enum {
	ND_NUM,
	ND_NEG,
	ND_ADDRESS, // &
	ND_DEREFER, // *
	ND_ADD, // +
	ND_SUB, // -
	ND_MUL, // *
	ND_DIV, // /
	ND_MOD, // %
	ND_EQ, // ==
	ND_NE, // !=
	ND_LT, // <
	ND_LE, // <=
	ND_ASSIGN, // = 
	ND_LVAR, // local variable
	ND_EXPR_STMT,
	ND_RETURN,
	ND_IF,
	ND_WHILE,
	ND_BLOCK,
	ND_FUNC_CALL,
	ND_DECLAR
}	t_nd_type;

typedef struct s_tree	t_tree;

struct s_tree
{
	t_nd_type	node_type;
	t_tree		*next;
	t_data_type	*data_type;
	union {
		// return, block
		t_tree	*child;
		// operator
		struct {
			t_tree	*lhs;
			t_tree	*rhs;
		};
		// if, while
		struct {
			t_tree	*cond;
			t_tree	*then;
			t_tree	*els;
		};
		// num
		int	value;
		// local variable
		t_var		*local_var;
		// function call
		struct {
			const char	*func_name;
			t_tree		*args;
		};
	};
};

#endif
