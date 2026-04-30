/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_path_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:10:48 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/05/01 08:08:39 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

static ssize_t	get_file_size(const char *file_path);

int	file_path_to_str(char **file_content, const char *file_path)
{
	ssize_t	size = get_file_size(file_path);
	if (size < 0)
		return (-1);
	*file_content = aalloc(size + 2);
	if (!*file_content)
	{
		perror("malloc");
		return (-1);
	}
	int	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (-1);
	}
	if (read(fd, *file_content, size) != size)
	{
		perror("read");
		return (close(fd), -1);
	}
	close(fd);
	if (size == 0 || (*file_content)[size - 1] != '\n')
		(*file_content)[size++] = '\n';
	(*file_content)[size] = '\0'; 
	return (0);
}

static ssize_t	get_file_size(const char *file_path)
{
	struct stat st;

	if (stat(file_path, &st) == -1)
	{
		perror("stat");
		return (-1);
	}
	return ((ssize_t)st.st_size);
}
