/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:36:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/05 22:00:10 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include "tree.h"
# include "local_variable.h"
# include "data_type.h"

typedef struct s_function	t_function;

struct s_function
{
	t_data_type	*data_type;
	const char	*name;
	int			argc;
	t_var_list	*locals;
	t_tree		*body;
	int			stack_size;
};

typedef struct s_func_list	t_func_list;

struct s_func_list
{
	t_function	*func;
	t_func_list	*next;
};

#endif
