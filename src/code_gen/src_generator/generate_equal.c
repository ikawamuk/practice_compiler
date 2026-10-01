/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_equal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:56:30 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/06/19 00:02:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	generate_equal(int assem_src_fd)
{
	dprintf(assem_src_fd, "\tcmp rax, rdi\n");
	dprintf(assem_src_fd, "\tsete al\n");
	dprintf(assem_src_fd, "\tmovzb rax, al\n");
}
