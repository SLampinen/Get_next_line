/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:36:21 by slampine          #+#    #+#             */
/*   Updated: 2022/11/18 09:36:44 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
#include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
size_t	ft_linelen(char *s);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
