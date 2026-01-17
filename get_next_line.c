/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 05:20:23 by fdeville          #+#    #+#             */
/*   Updated: 2026/01/17 18:13:28 by fdeville         ###   ########.fr       */
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
				if (!(*line))
					return (0);
			}
		}
	}
	return (1);
}

void	clear_buffer(char buffer[BUFFER_SIZE])
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[i] = 0;
		i++;
	}
}

int	gnloop(char buffer[BUFFER_SIZE], char **line, int r)
{
	int			idx;

	if (r == -1)
	{
		clear_buffer(buffer);
		if ((*line))
			free(*line);
		return (0);
	}
	idx = ft_strchr(buffer, '\n');
	if (idx < 0)
		*line = append(*line, buffer, 0, r - 1);
		if (!(*line))
			return (0);
	else
	{
		*line = append(*line, buffer, 0, idx);
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	int			r;

	line = NULL;
	if (!buffer_check(buffer, &line))
		return (line);
	r = 1;
	while (r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (!gnloop(buffer, &line, r))
			break ;
	}
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