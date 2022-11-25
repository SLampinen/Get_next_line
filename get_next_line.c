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
#include "get_next_line.h"
#include <unistd.h>

static char	*find_line(char *text)
{
	char	*line;
	int		line_len;

	if (ft_strchr(text, '\n'))
	{
		line_len = ft_linelen(text);
		line = malloc((line_len + 1) * sizeof(char *));
		if (!line)
			return (NULL);
		line[line_len + 1] = 0;
		while (line_len >= 0)
		{
		line[line_len] = text[line_len];
		line_len--;
		}
		return (line);
	}
	else
		return (NULL);
}

char		*get_next_line(int fd)
{
	static char	*storage;
	char 		*buffer;
	char		*current_line;
	int			read_bytes;
	int			num;

	num = 0;
	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!storage)
		storage = ft_strdup("\0");
	read_bytes = 5;
	while(read_bytes > 0)
	{
		current_line = find_line(storage);
		if (current_line != NULL)
		{
			while (storage[num] != '\n')
				num++;
			buffer = ft_strdup(storage + num + 1);
			while (*storage)
				*storage++ = 0;
			if (*storage)
				free(storage);
			storage = ft_strdup(buffer);
			while (*buffer)
				*buffer++ = 0;
			if (*buffer)
				free(buffer);
			return (current_line);
		}
		else
		{
			buffer = malloc((BUFFER_SIZE) * sizeof(char *));
			read_bytes = read(fd, buffer, BUFFER_SIZE);
			if (read_bytes > 0)
				storage = ft_strjoin(storage, buffer);
			while (*buffer)
				*buffer++ = 0;
			if (*buffer)
				free(buffer);
			current_line = ft_strdup(storage);
		}
	}
	if (read_bytes <= 0)
	{
		while (*storage)
			*storage++ = 0;
		if (*storage)
			free(storage);
	}
	return (current_line);
}