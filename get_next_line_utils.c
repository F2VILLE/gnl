/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 20:42:46 by fdeville          #+#    #+#             */
/*   Updated: 2026/01/17 16:43:08 by fdeville         ###   ########.fr       */
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

int	ft_strncpy(char *dst, char *src, int s)
{
	int	i;

	i = 0;
	if (!dst || !src)
		return (0);
	while (i < s)
	{
		dst[i] = src[i];
		i++;
	}
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
	tmp = (char *)malloc((dest_l + (end - start + 1) + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	i = ft_strncpy(tmp, dest, dest_l);
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

void	fill(char *dst, char c, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[i] = c;
		i++;
	}
}
