/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xaalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 06:47:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 06:57:30 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include <stdlib.h>
#include <stdio.h>

void	*xaalloc(size_t size)
{
	void	*p = aalloc(size);
	if (!p)
	{
		clear_arena();
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (p);
}
