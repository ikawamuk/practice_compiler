/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:36:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 08:24:47 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include "tree.h"
# include "local_variable.h"

typedef struct s_function	t_function;

struct s_function
{
	t_function	*next;
	const char	*name;
	t_tree		*node;
	t_var_list	*var_list;
};

typedef struct s_func_list	t_func_list;

struct s_func_list
{
	t_function	*func;
	t_func_list	*next;
};

#endif
