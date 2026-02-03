/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:08:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/03 15:30:47 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include <stddef.h>

typedef struct s_chunk	t_chunk;

struct s_chunk
{
	void	*buffer;
	size_t	size;
	size_t	offset;
	t_chunk	*next;
};

typedef struct s_arena
{
	t_chunk	dummy_head;
	t_chunk	*cur;
}	t_arena;

void	*aalloc(t_arena *arena, size_t size);
void	afree(t_arena *arena);
void	clear_arena(t_arena *arena);

#endif
