/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_div.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:58:21 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/06/19 00:02:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	generate_div(int assem_src_fd)
{
	dprintf(assem_src_fd, "\tcqo\n");
	dprintf(assem_src_fd, "\tidiv rdi\n");
}
