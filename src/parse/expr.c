/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:09:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/03 18:15:45 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "arena.h"
#include "token.h"

t_tree	*equality(t_arena *arena, t_token **token_p);

t_tree	*expr(t_arena *arena, t_token **token_p)
{
	return (equality(arena, token_p));
}
