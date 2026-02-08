/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_div.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:58:21 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 22:01:29 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	generate_div(FILE *asm_file)
{
	fprintf(asm_file, "\tcqo\n");
	fprintf(asm_file, "\tidiv rdi\n");
}
