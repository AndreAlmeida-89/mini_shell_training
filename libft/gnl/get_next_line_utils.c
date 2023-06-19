/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:55:56 by pvieira-          #+#    #+#             */
/*   Updated: 2023/01/02 09:52:30 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*pointer;
	size_t	l_s;

	if (!s1)
		return (ft_strdup(s2));
	l_s = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	pointer = (char *)malloc ((l_s + 1) * sizeof(*s1));
	if (!pointer)
		return (NULL);
	ft_memmove(pointer, s1, ft_strlen_gnl(s1));
	ft_memmove(pointer + ft_strlen_gnl(s1), s2, ft_strlen_gnl(s2));
	pointer[l_s] = '\0';
	free(s1);
	return (pointer);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	cont;

	cont = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		cont++;
		s++;
	}
	return (cont);
}

char	*ft_strdup(const char *s1)
{
	int		n_size;
	char	*pointer_1;

	n_size = ft_strlen_gnl(s1);
	pointer_1 = malloc((n_size + 1) * sizeof(char));
	if (!pointer_1)
		return (NULL);
	ft_memmove(pointer_1, s1, n_size);
	pointer_1[n_size] = '\0';
	return (pointer_1);
}
