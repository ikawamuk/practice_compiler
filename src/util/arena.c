/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:11:32 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 17:29:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static t_chunk	*next_chunk(size_t size);

static t_arena	arena = {0};

void	*aalloc(size_t size)
{
	size_t	aligned_size = (size + 7)&~7; // round up to 8 bytes
	if (!arena.cur)
		arena.cur = &arena.dummy_head;
	while (!arena.cur->buffer
		|| arena.cur->offset + aligned_size > arena.cur->size)
	{
		if (!arena.cur->next)
		{
			size_t	next_size = max(aligned_size + arena.cur->size * 2, MIN_ARENA_SIZE);
			t_chunk	*next = next_chunk(next_size);
			if (!next)
				return (NULL);
			arena.cur->next = next;
		}
		arena.cur = arena.cur->next;
	}
	void	*p = arena.cur->buffer + arena.cur->offset;
	arena.cur->offset += aligned_size;
	return (p);
}

void	areset()
{
	t_chunk *cur = arena.dummy_head.next;

	while (cur)
	{
		cur->offset = 0;
		cur = cur->next;
	}
	arena.cur = &arena.dummy_head;
}

static t_chunk	*next_chunk(size_t size)
{
	t_chunk	*next = malloc(sizeof(t_chunk));
	if (!next)
		return (perror("malloc"), NULL);
	next->buffer = malloc(size * sizeof(char));
	if (!next->buffer)
		return (perror("malloc"), free(next), NULL);
	next->size = size;
	next->offset = 0;
	next->next = NULL;
	return (next);
}

void	clear_arena()
{
	t_chunk	*cur = arena.dummy_head.next;
	t_chunk	*next;

	while (cur)
	{
		next = cur->next;
		free(cur->buffer);
		free(cur);
		cur = next;
	}
	arena.dummy_head.next = NULL;
	arena.cur = NULL;
}
