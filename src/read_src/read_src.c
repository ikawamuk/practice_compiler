/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_src.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:55:43 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 03:56:37 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "file_info.h"
#include <stdio.h>
#include <stdlib.h>

static t_file_info	src_info;

char		*file_path_to_str(const char *file_path);
static void	set_src_info(char *file_name, char *content_head);

char	*read_src(const char *file_path)
{
	char *file_content = file_path_to_str(file_path);
	if (!file_content)
	{
		perror("read_src");
		return (NULL);
	}
	set_src_info((char *)file_path, file_content);
	return (file_content);
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
