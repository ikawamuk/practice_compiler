/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 01:50:12 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/05 22:31:27 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char		*get_src_name(void);
char		*get_content_head(void);
static int	count_pos(const char *start, const char *loc, int indent);

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
	int	pos = count_pos(line_start, location, indent);
	fprintf(stderr, "%*s", pos, "");
	fprintf(stderr, "^ %s\n", err_msg);
}

static int	count_pos(const char *start, const char *loc, int indent)
{
	static int	TAB_WIDTH = 8;
	int	pos = indent;
	while (start < loc)
	{
		if (*start++ == '\t')
			pos += (TAB_WIDTH - (pos % TAB_WIDTH));
		else
			pos++;
	}
	return (pos);
}
