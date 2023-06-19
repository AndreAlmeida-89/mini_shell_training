/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 08:43:00 by pvieira-          #+#    #+#             */
/*   Updated: 2022/06/13 18:42:00 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*pointer;
	size_t			i;
	size_t			j;
	unsigned int	l_s;

	if (!s)
		return (NULL);
	l_s = (ft_strlen(s));
	if (start > l_s)
		return (ft_strdup(""));
	if (len > l_s)
		pointer = (char *)malloc (sizeof(*pointer) * (l_s + 1));
	else
		pointer = (char *)malloc (sizeof(*pointer) * (len +1));
	if (!pointer)
		return (NULL);
	i = 0;
	j = start;
	while (j < (start + len) && s[j] != '\0')
		pointer[i++] = s[j++];
	pointer[i] = '\0';
	return (pointer);
}
