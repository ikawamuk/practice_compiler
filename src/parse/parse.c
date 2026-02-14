/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:05:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 18:43:50 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "arena.h"
#include "token.h"
#include "program.h"
#include <stdlib.h>

t_program	*program(t_token **token_p);

t_program	*parse(t_token *token_list)
{
	t_program	*prog = program(&token_list);
	if (!prog)
	{
		clear_arena();
		exit(EXIT_FAILURE);
	}
	return (prog);
}
