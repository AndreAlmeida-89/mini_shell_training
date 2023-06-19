/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:58:32 by pvieira-          #+#    #+#             */
/*   Updated: 2022/07/04 17:33:01 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_udec(unsigned int udec)
{
	int	ret_count;

	ret_count = 0;
	if (udec == 0)
		ret_count++;
	while (udec != 0)
	{
		udec = udec / 10;
		ret_count++;
	}
	return (ret_count);
}

static void	u_putnbr(unsigned int num)
{
	if (num < 10)
		ft_putchar_fd((num + '0'), 1);
	if (num >= 10)
	{
		u_putnbr(num / 10);
		u_putnbr(num % 10);
	}
}

int	out_u(va_list lst)
{
	unsigned int	num;
	int				ret_count;

	num = va_arg(lst, unsigned int);
	ret_count = count_udec(num);
	u_putnbr(num);
	return (ret_count);
}
