/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/24 13:51:44 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include <stdio.h>
#include <stdlib.h>

int	run_compiler(char **argv);

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "no input file");
		return (EXIT_FAILURE);
	}
	return (run_compiler(argv));
}
