/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:36:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 18:51:45 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_H
# define PROGRAM_H

# include "tree.h"
# include "local_variable.h"

typedef struct s_program
{
	t_tree	*ast;
	t_lvar	*var_list;
}	t_program;

#endif
