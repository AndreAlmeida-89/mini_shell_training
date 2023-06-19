/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:25:28 by pvieira-          #+#    #+#             */
/*   Updated: 2022/06/12 17:58:01 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = (ft_strlen(s) + 1);
	while (i-- > 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + (i));
	}
	return (NULL);
}
