/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:18:37 by pvieira-          #+#    #+#             */
/*   Updated: 2022/05/22 11:18:55 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pointer;
	size_t	l_s;
	size_t	i;

	if (!(s1 && s2))
		return (NULL);
	l_s = ft_strlen(s1) + ft_strlen(s2);
	pointer = (char *)malloc ((l_s + 1) * sizeof(*s1));
	if (!pointer)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		pointer[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		pointer[i] = *s2;
		i++;
		s2++;
	}
	pointer[i] = '\0';
	return (pointer);
}
