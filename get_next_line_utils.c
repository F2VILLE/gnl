/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 20:42:46 by fdeville          #+#    #+#             */
/*   Updated: 2026/01/09 21:00:48 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	tmp = (char *)malloc((dest_l + (end - start) + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < dest_l)
	{
		tmp[i] = dest[i];
		i++;
	}
	if (i > 0 && tmp[i - 1] == '\0')
		i--;
	while (start <= end)
	{
		tmp[i] = buffer[start];
		i++;
		start++;
	}
	tmp[i] = '\0';
	if (dest)
		free(dest);
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

void fill(char *dst, char c, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[i] = c;
		i++;
	}
}
#include <stdio.h>
void	shift_buff(char buffer[BUFFER_SIZE])
{
	int	idx;
	int	i;

	idx = ft_strchr(buffer, '\n');
	printf("Shifting buffer (idx %d)\nBuffer :\n```\n", idx);
	for (int j = 0; j < BUFFER_SIZE; j++)
	{
		printf("buff[%d] = `%c`\n", j, buffer[j] == '\n' ? '@' : buffer[j]);
	}
	printf("\n```\n");
	i = 0;
	if (idx < 0)
	{
		fill(buffer, 0, BUFFER_SIZE);
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
