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

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

size_t	ft_linelen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != '\n')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		inds;
	int		indd;

	indd = 0;
	inds = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1);
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
