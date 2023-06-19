/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 09:22:33 by pvieira-          #+#    #+#             */
/*   Updated: 2022/05/18 09:39:51 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		comp;

	if (n == 0)
		return (0);
	i = 0;
	comp = 0;
	while (i < (n - 1) && s1[i] != '\0' && s1[i] == s2[i])
		i++;
	comp = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (comp);
}
