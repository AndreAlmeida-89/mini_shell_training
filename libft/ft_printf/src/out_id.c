/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_id.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:37:13 by pvieira-          #+#    #+#             */
/*   Updated: 2022/07/05 10:37:35 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_dec(int dec)
{
	int	ret_count;

	ret_count = 0;
	if (dec <= 0)
		ret_count++;
	while (dec != 0)
	{
		dec = dec / 10;
		ret_count++;
	}
	return (ret_count);
}

int	out_id(va_list lst)
{
	int	num;
	int	ret_count;

	num = va_arg(lst, int);
	ret_count = count_dec(num);
	ft_putnbr_fd(num, 1);
	return (ret_count);
}
