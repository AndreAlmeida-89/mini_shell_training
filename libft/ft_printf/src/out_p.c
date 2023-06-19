/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:18:01 by pvieira-          #+#    #+#             */
/*   Updated: 2022/07/09 10:00:07 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	number_len(long unsigned num)
{
	int	count;

	count = 0;
	if (num == 0)
		count++;
	while (num != 0)
	{
		num = num / 16;
		count++;
	}
	return (count);
}

static void	ft_dec_hex_mem(long unsigned dec)
{
	if (dec >= 16)
	{
		ft_dec_hex_mem(dec / 16);
		dec = dec % 16;
	}
	if (dec < 10)
		ft_putchar_fd((dec + 48), 1);
	else
		ft_putchar_fd((dec + (97 - 10)), 1);
}

int	out_p(va_list lst)
{
	long unsigned	mem;

	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	mem = va_arg(lst, long unsigned);
	ft_dec_hex_mem(mem);
	return (number_len(mem) + 2);
}
