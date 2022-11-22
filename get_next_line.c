/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:18:20 by slampine          #+#    #+#             */
/*   Updated: 2022/11/17 10:18:22 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "get_next_line.h"
#include "get_next_line_utils.c"

/*char	*get_next_line(int fd)
{
	char		*current_line;
	static char	*text;
	char		*buffer;
	static int	start;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!text)
	{
		text = malloc((BUFFER_SIZE + 1) * sizeof(char *));
		start = 0;
	}
	if (!text)
		return (NULL);
	read(fd, text, BUFFER_SIZE);
	while (read(fd, buffer, BUFFER_SIZE))
		ft_strjoin(text, buffer);
	free(buffer);
	current_line = malloc((ft_linelen(text) + 1) * sizeof(char *));
	while (text[start] != '\n' && text[start] != '\0')
	{
		current_line[i] = text[start];
	}
	
	return (current_line);
}*/

char	*get_next_line(int fd)
{
	static int	fp;
	static char	*storage;
	char 		*buffer;
	char		*current_line;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!fp)
		fp = BUFFER_SIZE;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (fp == BUFFER_SIZE)
	{
		fp = 0;
		while (read_bytes == read(fd, buffer, BUFFER_SIZE))
		{
			current_line = malloc((read_bytes - fp + 1) * sizeof(char *));
			while (buffer[fp] != '\n' && fp < read_bytes)
			{
				*current_line++ = buffer[fp++];
			}
			
		}
	}
	return (current_line);
}