/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:26:36 by pvieira-          #+#    #+#             */
/*   Updated: 2022/05/14 15:52:52 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	d;

	p = (unsigned char *)s;
	d = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (p[i] == d)
			return (p + i);
		i++;
	}
	return (NULL);
}
