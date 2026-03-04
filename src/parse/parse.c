/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:05:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 21:24:23 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "arena.h"
#include "token.h"
#include "function.h"
#include <stdlib.h>
#include <stdio.h>

t_func_list	*program(t_token **token_p);
void		assign_type(t_func_list *prog);

t_func_list	*parse(t_token *token_list)
{
	t_func_list	*prog = program(&token_list);
	assign_type(prog);
	return (prog);
}
