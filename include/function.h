/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:36:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 07:48:07 by ikawamuk         ###   ########.fr       */
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
	t_lvar		*var_list;
};

#endif
