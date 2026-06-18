/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/06/19 00:03:11 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include <stdio.h>
#include <stdlib.h>

int	run_compiler(char **file_names);

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		dprintf(2, "no input file\n");
		dprintf(2, "Usage: ccc < C file > < object file to link... >\n");
		return (EXIT_FAILURE);
	}
	return (run_compiler(argv + 1));
}
