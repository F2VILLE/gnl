/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 05:20:23 by fdeville          #+#    #+#             */
/*   Updated: 2026/01/08 06:40:13 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*append(char *dest, char buffer[BUFFER_SIZE], int start, int end)
{
	int		dest_l;
	int		i;
	char	*tmp;

	if (end < start)
		return (dest);
	dest_l = ft_strlen(dest);
	printf("Append buffer (from %d to %d) to line (len %d)\n", start, end, dest_l);
	tmp = (char *)malloc((dest_l + (end - start) + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < dest_l)
	{
		tmp[i] = dest[i];
		i++;
	}
	if (tmp[i - 1] == '\0')
		i--;
	while (start <= end)
	{
		tmp[i + start] = buffer[start];
		start++;
	}
	tmp[i + start] = '\0';
	// printf("Tmp = `%s`\n", tmp);
	// if (dest)
		// free(dest);
	return (tmp);
}

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
	if (idx < 0)
	{
		buffer[0] = 0;
	}
	else
	{
		idx++;
		while ((idx + i) < BUFFER_SIZE)
		{
			buffer[i] = buffer[idx + i];
			i++;
		}
		buffer[i] = '\0';
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	int			r;
	int			idx;

	if (buffer[0] != '\0')
	{
		idx = ft_strchr(buffer, '\n');
		if (idx < 0)
			line = append(line, buffer, 0, ft_strlen(buffer));
		else
			line = append(line, buffer, idx, BUFFER_SIZE - 1);
	}
	r = read(fd, buffer, BUFFER_SIZE);
	idx = 0;
	while (r > 0)
	{
		// printf("====  [DEBUG]  ====\n r = %d\n buff = %s\n====  [DEBUG]  ====\n", r, buffer);
		idx = ft_strchr(buffer, '\n');
		printf("idx %d\n", idx);
		if (idx < 0)
		{
			line = append(line, buffer, 0, BUFFER_SIZE - 1);
			r = read(fd, buffer, BUFFER_SIZE);
		}
		else
		{
			line = append(line, buffer, 0, idx);
			break ;
		}
		// printf("[DEBUG] line after append : `%s`\n", line);
	}
	printf("buffer before shift : `%s`\n", buffer);
	shift_buff(buffer);
	printf("buffer after shift : `%s`\n", buffer);
	return (line);
}
