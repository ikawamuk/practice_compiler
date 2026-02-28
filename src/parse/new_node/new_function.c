/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 08:39:08 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 09:21:43 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include <stddef.h>

void	*xaalloc(size_t size);

t_function	*new_function(t_function func_data)
{
	t_function	*function = xaalloc(sizeof(t_function));
	function->name = func_data.name;
	function->params = func_data.params;
	function->body = func_data.body;
	function->locals = func_data.locals;
	if (function->params)
		function->stack_size += function->params->var->offset;
	if (function->locals)
		function->stack_size += function->locals->var->offset;
	return (function);
}