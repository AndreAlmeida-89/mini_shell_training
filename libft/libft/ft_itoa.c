/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 06:56:30 by pvieira-          #+#    #+#             */
/*   Updated: 2022/05/26 21:04:24 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_num_size(long int num)
{
	int	count;

	count = 0;
	if (num == 0)
		count++;
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

static	char	*ft_itoan(long int num)
{
	int		i;
	int		ln_size;
	char	*pointer;

	num = -1 * num;
	ln_size = ft_num_size(num);
	pointer = (char *)malloc(ln_size + 1 + 1);
	if (!pointer)
		return (NULL);
	pointer[0] = '-';
	i = 1;
	while (ln_size > 0)
	{
		pointer[ln_size] = (num % 10 + 48);
		num = num / 10;
		ln_size--;
		i++;
	}
	pointer[i] = '\0';
	return (pointer);
}

static	char	*ft_itoap(long int num)
{
	int		i;
	int		ln_size;
	char	*pointer;

	ln_size = ft_num_size(num);
	pointer = (char *)malloc(ln_size + 1);
	if (!pointer)
		return (NULL);
	i = 0;
	while ((ln_size - 1) >= 0)
	{
		pointer[ln_size - 1] = (num % 10 + 48);
		num = num / 10;
		ln_size--;
		i++;
	}
	pointer[i] = '\0';
	return (pointer);
}

char	*ft_itoa(int n)
{
	long int	num;
	char		*pointer;

	num = (long int)n;
	if (num < 0)
		pointer = ft_itoan(num);
	else
		pointer = ft_itoap(num);
	return (pointer);
}
