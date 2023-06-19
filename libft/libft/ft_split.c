/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:30:13 by pvieira-          #+#    #+#             */
/*   Updated: 2022/06/13 19:23:41 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_w(char const *s, char c)
{
	int		count;
	size_t	i;
	int		mk;

	i = 0;
	count = 0;
	mk = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == c) && (s[i] != '\0'))
			i++;
		while ((s[i] != c) && (s[i] != '\0'))
		{
			mk = 1;
			i++;
		}
		if (mk == 1)
			count++;
		mk = 0;
	}
	return (count);
}

static	int	count_l(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static	char	**testpointer(char **pointer, size_t i)
{
	while (i > 0)
	{
		free(pointer[i - 1]);
		i--;
	}
	free(pointer);
	return (NULL);
}

static	char	**split(char const *s, size_t c_w, char **pointer, char c)
{
	size_t	i;

	i = 0;
	while (i < c_w)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			pointer[i] = ft_substr(s, 0, count_l(s, c));
			if (!pointer[i])
				return (testpointer(pointer, i));
		}
		s = s + count_l(s, c);
		i++;
	}
	return (pointer);
}

char	**ft_split(char const *s, char c)
{
	char	**pointer;
	char	**p2;
	size_t	c_w;

	if (!s)
		return (NULL);
	c_w = count_w(s, c);
	pointer = malloc(sizeof(char *) * (c_w + 1));
	if (!pointer)
		return (NULL);
	pointer[c_w] = NULL;
	p2 = split(s, c_w, pointer, c);
	return (p2);
}
