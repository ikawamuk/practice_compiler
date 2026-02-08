/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 01:50:12 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/03 18:29:10 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	error_at(const char *input_str, const char *location, const char *err_msg)
{
	const int	pos = location - input_str;

	fprintf(stderr, "%s\n", input_str);
	fprintf(stderr, "%*s", pos, " ");
	fprintf(stderr, "^ ");
	fprintf(stderr, "%s\n", err_msg);
	return ;
}