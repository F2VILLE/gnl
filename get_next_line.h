/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 05:20:43 by fdeville          #+#    #+#             */
/*   Updated: 2026/01/09 16:36:27 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*append(char *dest, char buffer[BUFFER_SIZE], int start, int end);
int		ft_strlen(char *s);
int		ft_strchr(char buffer[BUFFER_SIZE], char c);
void	shift_buff(char buffer[BUFFER_SIZE]);
int		empty_buffer_in_line(char *line, char buffer[BUFFER_SIZE]);

#endif