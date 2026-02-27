/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_variable.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 22:50:00 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 08:21:49 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCAL_VARIABLE_H
# define LOCAL_VARIABLE_H

#include  "token.h"

typedef struct s_var
{
	char	*name;
	int		offset;
}	t_var;

typedef struct s_var_list	t_var_list;

struct s_var_list
{
	t_var		*var;
	t_var_list	*next;
};

#endif
