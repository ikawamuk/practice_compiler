/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_src.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:55:43 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/05/01 08:09:21 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "file_info.h"
#include <stdio.h>
#include <stdlib.h>

static t_file_info	src_info;

int	file_path_to_str(char **file_content, const char *file_path);
static void	set_src_info(char *file_name, char *content_head);

int	read_src(char **file_content, const char *file_path)
{
	if (file_path_to_str(file_content, file_path) < 0)
		return (-1);
	set_src_info((char *)file_path, *file_content);
	return (0);
}

char	*get_content_head(void)
{
	return (src_info.content_head);
}

char	*get_src_name(void)
{
	return (src_info.file_name);
}

static void	set_src_info(char *file_name, char *content_head)
{
	src_info.file_name = file_name;
	src_info.content_head = content_head;
}
