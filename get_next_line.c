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
		line_len = ft_len(text, '\n');
		line = malloc((line_len + 1) * sizeof(char *));
		if (!line)
			return (NULL);
		line[line_len] = 0;
		while (line_len > 0)
		{
			line_len--;
			line[line_len] = text[line_len];
		}
		return (line);
	}
	else
		return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buffer;
	char		*current_line;
	char		*temp;
	int			read_bytes;

	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	read_bytes = 1;
	if (!storage)
		storage = ft_calloc((BUFFER_SIZE), sizeof(char *));
	while (read_bytes > 0)
	{
		current_line = find_line(storage);
		if (current_line != NULL)
		{
			temp = ft_substr(storage, ft_len(current_line, '\0'), ft_len(storage, '\0'));
			free(storage);
			storage = temp;
			return (current_line);
		}
		else
		{
			buffer = malloc((BUFFER_SIZE) * sizeof(char *));
			read_bytes = read(fd, buffer, BUFFER_SIZE);
			if (read_bytes > 0)
			{
				temp = ft_strjoin(storage, buffer);
				storage = temp;
			}
			free(buffer);
		}
	}
	current_line = ft_substr(storage, 0 , ft_len(storage, '\0'));
	storage = NULL;
	return (current_line);
}