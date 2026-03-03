/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 01:50:12 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 04:17:20 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include <stdio.h>
#include <stdlib.h>

char	*get_src_name(void);
char	*get_content_head(void);

void	error_at(const char *location, const char *err_msg)
{
	const char	*line_start = location;
	const char	*line_end = location;
	while (get_content_head() < line_start && line_start[-1] != '\n')
		line_start--;
	while (*line_end && *line_end != '\n')
		line_end++;
	int line_num = 1;
	for (char *p = get_content_head(); p < line_start; p++)
		if (*p == '\n')
			line_num++;
	int indent = fprintf(stderr, "%s:%d: ", get_src_name(), line_num);
	fprintf(stderr, "%.*s\n", (int)(line_end - line_start), line_start);
	int	pos = location - line_start + indent;
	fprintf(stderr, "%*s", pos, " ");
	fprintf(stderr, "^ %s\n", err_msg);
}
