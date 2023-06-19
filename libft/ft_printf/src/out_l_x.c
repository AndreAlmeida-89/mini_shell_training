/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_l_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:56:03 by pvieira-          #+#    #+#             */
/*   Updated: 2022/07/09 09:59:27 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	number_len(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
		count++;
	while (num != 0)
	{
		num /= 16;
		count++;
	}
	return (count);
}

int	out_l_x(va_list lst)
{
	unsigned int	mem;

	mem = va_arg(lst, unsigned int);
	ft_dec_hex_l(mem);
	return (number_len(mem));
}
