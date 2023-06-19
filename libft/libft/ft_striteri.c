/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:44:47 by pvieira-          #+#    #+#             */
/*   Updated: 2022/05/26 21:07:07 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	size_t	l_s;

	if (!s)
		return ;
	i = 0;
	l_s = ft_strlen(s);
	while (i < l_s)
	{
		f((unsigned int)i, &s[i]);
		i++;
	}
}
