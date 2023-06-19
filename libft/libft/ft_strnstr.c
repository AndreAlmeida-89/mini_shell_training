/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:59:26 by pvieira-          #+#    #+#             */
/*   Updated: 2022/05/20 10:07:29 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l_little;
	char	*p;

	p = (char *)big;
	l_little = ft_strlen(little);
	i = 0;
	if (! l_little)
		return (p);
	while (p[i] != '\0' && i < len)
	{
		j = 0;
		while (p[i + j] == little[j] && i + j < len)
		{
			if (little [j + 1] == '\0')
			{
				return (p + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
