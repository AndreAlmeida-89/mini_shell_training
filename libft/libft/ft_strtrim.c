/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:43:35 by pvieira-          #+#    #+#             */
/*   Updated: 2022/06/14 08:40:20 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	l_s1;
	char	*pointer;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
			s1++;
	l_s1 = ft_strlen(s1);
	while (l_s1 > 0 && ft_strchr(set, s1[l_s1]))
		l_s1--;
	pointer = ft_substr(s1, 0, (l_s1 + 1));
	return (pointer);
}
