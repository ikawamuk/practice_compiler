/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:11:32 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 13:05:35 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include <stdio.h>

void	*alloc(t_arena *arena, size_t size)
{
	void	*p;
	size_t	aligned_size = (size + 7)&~7; // (size + 7) / 8 * 8

	if (arena->offset + aligned_size > arena->size)
		return (NULL);
	p = arena->buffer + arena->offset;
	arena->offset += aligned_size;
	return (p);
}
