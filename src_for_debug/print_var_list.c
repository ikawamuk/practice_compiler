/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_var_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 22:20:53 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 22:24:06 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "local_variable.h"
#include <stdio.h>

void	print_var(t_var *var);

void	print_var_list(t_var_list *list)
{
	for (t_var_list *cur = list; cur; cur = cur->next)
	{
		print_var(cur->var);
	}
}

void	print_var(t_var *var)
{
	printf("var name:%s\n", var->name);
	printf("offset:%d\n", var->offset);
}
