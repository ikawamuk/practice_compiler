/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 08:39:08 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 08:46:11 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include <stddef.h>

void	*xaalloc(size_t size);

t_function	*new_function(const char *name, t_tree *body, t_var_list *var_list)
{
	t_function	*function = xaalloc(sizeof(t_function));
	function->name = name;
	function->body = body;
	function->locals = var_list;
	function->stack_size = var_list ? var_list->var->offset : 0;
	return (function);
}