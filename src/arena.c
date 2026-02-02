/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:11:32 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 12:18:36 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void	*alloc(t_arena *arena, size_t size)
{
	void	*p;

	if (arena->offset + size > arena->size)
		return (NULL);
	p = arena->buffer + arena->offset;
	arena->offset += size;
	return (p);
}
