/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 02:54:13 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 08:14:22 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include "local_variable.h"

typedef enum {
	ND_NUM,
	ND_NEG,
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
	ND_EXPR_STMT,
	ND_RETURN,
	ND_IF,
	ND_WHILE,
	ND_BLOCK,
	ND_FUNC_CALL
}	t_nd_type;

typedef struct s_tree	t_tree;

struct s_tree
{
	t_nd_type	type;
	t_tree		*next;
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
			char	*func_name;
			t_tree	*args;
		};
	};
};

#endif
