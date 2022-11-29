/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:36:10 by slampine          #+#    #+#             */
/*   Updated: 2022/11/18 09:36:13 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t ft_len(char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c)
		len++;
	if (c == '\n')
		len++;
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	char	*s;
	char	nd;

	nd = (char )c;
	s = (char *)str;
	while (*s != nd)
	{
		if (!*s)
			return (0);
		s++;
	}
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		inds;
	int		indd;

	indd = 0;
	inds = 0;
	if (!s1 && !s2)
		return (NULL);
	str = malloc(ft_len((char *) s1, '\0') + ft_len((char *) s2, '\0') + 1);
	if (!str)
		return (NULL);
	while (s1[inds] != '\0')
	{
		str[indd++] = s1[inds++];
	}
	inds = 0;
	while (s2[inds] != '\0')
	{
		str[indd++] = s2[inds++];
	}
	str[indd] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	srclen;

	i = 0;
	if (!s)
		return (NULL);
	srclen = ft_len((char *)s, '\0');
	if (srclen < start)
	{
		new = ft_calloc(1, sizeof(char *));
		return (new);
	}
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		new[i] = s[start];
		start++;
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (count * size < count || count * size < size)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr)
		while(count-- > 0)
			*ptr++ = 0;
	return (ptr);
}