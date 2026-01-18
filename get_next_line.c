/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 05:20:23 by fdeville          #+#    #+#             */
/*   Updated: 2026/01/18 04:28:20 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	shift_buff(char buffer[BUFFER_SIZE])
{
	int	idx;
	int	i;

	idx = ft_strchr(buffer, '\n');
	i = 0;
	if (idx < 0)
	{
		fill(buffer, 0, BUFFER_SIZE);
	}
	else
	{
		idx++;
		while ((i) < BUFFER_SIZE)
		{
			if (idx + i < BUFFER_SIZE)
				buffer[i] = buffer[idx + i];
			else
				buffer[i] = 0;
			i++;
		}
	}
}

int	buffer_check(char buffer[BUFFER_SIZE], char **line)
{
	int	idx;

	if (buffer[0])
	{
		shift_buff(buffer);
		if (ft_strlen(buffer))
		{
			idx = ft_strchr(buffer, '\n');
			if (idx > -1)
			{
				*line = append(*line, buffer, 0, idx);
				return (0);
			}
			else
			{
				*line = append(*line, buffer, 0, ft_strlen(buffer));
			}
		}
	}
	return (1);
}

int	gnloop(char buffer[BUFFER_SIZE], char **line, int r)
{
	int	idx;

	if (r < BUFFER_SIZE)
		fill(buffer + r, 0, BUFFER_SIZE - r);
	idx = ft_strchr(buffer, '\n');
	if (idx < 0)
		*line = append(*line, buffer, 0, r - 1);
	else
	{
		*line = append(*line, buffer, 0, idx);
		return (0);
	}
	if (!*line)
		return (-1);
	return (1);
}

int	process_read(int fd, char buffer[BUFFER_SIZE], char **line)
{
	int	r;
	int	ret;

	r = read(fd, buffer, BUFFER_SIZE);
	if (r <= 0)
		return (0);
	ret = gnloop(buffer, line, r);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	int			check;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		fill(buffer, 0, BUFFER_SIZE);
		return (NULL);
	}
	if (!buffer_check(buffer, &line))
		return (line);
	check = 1;
	while (check == 1)
		check = process_read(fd, buffer, &line);
	if (check == -1)
		return (free(line), NULL);
	return (line);
}
/*
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	printf("Argc : %d\n", argc);
	if (argc != 2)
	{
		printf("Usage: %s <file>", argv[0]);
		return (0);
	}
	int fd = open(argv[1], O_RDONLY);
	printf("Fd: %d\n", fd);
	if (fd < 0)
	{
		printf("Error opening file");
		return (1);
	}
	char    *line;
	int     i;

	i = 0;
	line = get_next_line(fd);
	printf("Meow");
	while (line)
	{
		printf("Line : %s\n", line);
		free(line);
		line = get_next_line(fd);
	}

	return (0);
}
*/