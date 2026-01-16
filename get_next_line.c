/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 05:20:23 by fdeville          #+#    #+#             */
/*   Updated: 2026/01/16 13:50:08 by fdeville         ###   ########.fr       */
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
	printf("GET_NEXT_LINE CALLED > BUFFER = ```\n");
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (buffer[i] < 32)
			printf("[0x%X]\n", buffer[i]);
		else
			printf("[%c]\n", buffer[i]);
	}
	printf("```\n");

	r = 1;
	while (r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r < BUFFER_SIZE)
		{
			printf("Read less than buffer size !!!");
		}
		idx = ft_strchr(buffer, '\n');
		printf("read %d; idx %d\n", r, idx);
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
