/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 08:39:08 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/01 19:38:10 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include <stddef.h>

void	*xaalloc(size_t size);

t_function	*new_function(t_function func_data)
{
	t_function	*function = xaalloc(sizeof(t_function));
	function->name = func_data.name;
	function->argc = func_data.argc;
	function->body = func_data.body;
	function->locals = func_data.locals;
	t_var_list *cur = func_data.locals;
	while (cur->next)
		cur = cur->next;
	function->stack_size = cur->var->offset;
	return (function);
}


