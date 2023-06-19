/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:33:18 by pvieira-          #+#    #+#             */
/*   Updated: 2022/06/11 10:00:04 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;

	if (count == 0 || size == 0)
	{
		size = 1;
		count = size;
	}
	pointer = malloc(count * size);
	if (!pointer || (((count * size) / count) != size))
		return (NULL);
	ft_bzero(pointer, count * size);
	return (pointer);
}
