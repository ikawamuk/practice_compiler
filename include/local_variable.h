/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 22:50:00 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 18:36:56 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCAL_VARIABLE_H
# define LOCAL_VARIABLE_H

#include  "token.h"

typedef struct s_lvar   t_lvar;

struct s_lvar
{
    const char      *name;
    size_t          len;
    int             offset;
    t_lvar          *next;
};

#endif
