/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:18:35 by pvieira-          #+#    #+#             */
/*   Updated: 2022/06/12 18:22:02 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	l_s;
	char	*pointer;

	if (!s)
		return (NULL);
	i = 0;
	pointer = ft_strdup(s);
	if (!pointer)
		return (NULL);
	l_s = ft_strlen(s);
	while (i < l_s)
	{
		pointer[i] = f((unsigned int)i, pointer[i]);
		i++;
	}
	return (pointer);
}
