/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 05:20:23 by fdeville          #+#    #+#             */
/*   Updated: 2026/01/16 16:35:04 by fdeville         ###   ########.fr       */
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
	int			idx;

	idx = ft_strchr(buffer, '\n');
	if (idx < 0)
		*line = append(*line, buffer, 0, r - 1);
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
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (buffer[i] < 32)
			printf("[0x%X]", buffer[i]);
		else
			printf("[%c]", buffer[i]);
	}
	printf("\n");
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
