/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:35:18 by pvieira-          #+#    #+#             */
/*   Updated: 2022/06/12 18:16:46 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		n_size;
	char	*pointer_1;

	n_size = ft_strlen(s1);
	pointer_1 = malloc((n_size + 1) * sizeof(char));
	if (!pointer_1)
		return (NULL);
	ft_memmove(pointer_1, s1, n_size);
	pointer_1[n_size] = '\0';
	return (pointer_1);
}
