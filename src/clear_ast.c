/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 03:34:15 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 11:25:08 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdlib.h>

void	clear_ast(t_tree *node)
{
	if (!node)
		return ;
	clear_ast(node->lhs);
	clear_ast(node->rhs);
	free(node);
	return ;
}
