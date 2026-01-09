/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:31:26 by fdeville          #+#    #+#             */
/*   Updated: 2026/01/09 20:41:56 by fdeville         ###   ########.fr       */
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

int	empty_buffer_in_line(char *line, char buffer[BUFFER_SIZE])
{
	int	idx;

	shift_buff(buffer);
	if (ft_strlen(buffer))
	{
		idx = ft_strchr(buffer, '\n');
		if (idx > -1)
		{
			line = append(line, buffer, 0, idx);
			return (0);
		}
		else
		{
			line = append(line, buffer, 0, ft_strlen(buffer));
		}
	}
	return (1);
}

static void	fill(char *b, char c, int s)
{
	int	i;

	i = 0;
	while (i < s)
	{
		b[i] = c;
		i++;
	}
}

static char	*copy(char *dst, char *src, int s)
{
	int	i;

	i = 0;
	if (!dst || !src)
		return (NULL);
	while (i < s)
	{
		dst[i] = src[i];
		s++;
	}
	return (dst);
}

char	*append(char *dest, char buffer[BUFFER_SIZE], int start, int end)
{
	int		dest_l;
	int		i;
	char	*tmp;

	if (end < start)
		return (dest);
	dest_l = ft_strlen(dest);
	tmp = (char *)malloc((dest_l
				+ (end - start + 1) /* sliced buffer (+1 -> end included)*/
				+ 1 /* \0 */) * sizeof(char));
	if (!tmp)
		return (NULL);
	fill(tmp, 0, (dest_l + (end - start) + 1));
	copy(tmp, dest, dest_l);
	i = dest_l;
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
