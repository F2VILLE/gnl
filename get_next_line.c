/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 05:20:23 by fdeville          #+#    #+#             */
/*   Updated: 2026/01/09 20:48:52 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	int			r;
	int			idx;

	line = NULL;

	if (buffer[0])
	{
		shift_buff(buffer);
		if (ft_strlen(buffer))
		{
			idx = ft_strchr(buffer, '\n');
			if (idx > -1)
			{
				line = append(line, buffer, 0, idx);
				return (line);
			}
			else
			{
				line = append(line, buffer, 0, ft_strlen(buffer));
			}
		}
	}
	r = 1;
	while (r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		idx = ft_strchr(buffer, '\n');
		if (idx < 0)
			line = append(line, buffer, 0, r - 1);
		else
		{
			line = append(line, buffer, 0, idx);
			break ;
		}
	}
	return (line);
}
