/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 05:20:23 by fdeville          #+#    #+#             */
/*   Updated: 2026/01/09 20:40:36 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char buffer[BUFFER_SIZE], char c)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && buffer[i])
	{
		if (buffer[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	shift_buff(char buffer[BUFFER_SIZE])
{
	int	idx;
	int	i;

	idx = ft_strchr(buffer, '\n');
	i = 0;
	if (idx >= 0)
	{
		idx++;
		while ((idx + i) < BUFFER_SIZE)
		{
			buffer[i] = buffer[idx + i];
			i++;
		}
	}
	while (i < BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	int			r;
	int			idx;

	line = NULL;
	if (buffer[0])
		if (!empty_buffer_in_line(line, buffer))
			return (line);
	r = 1;
	idx = 0;
	while (r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		idx = ft_strchr(buffer, '\n');
		if (idx < 0)
			line = append(line, buffer, 0, r - 1);
		if (idx >= 0)
		{
			line = append(line, buffer, 0, idx);
			break ;
		}
	}
	return (line);
}
