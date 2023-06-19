/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_hex_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 09:23:41 by pvieira-          #+#    #+#             */
/*   Updated: 2022/07/02 16:26:27 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dec_hex_l(unsigned int dec)
{
	if (dec >= 16)
	{
		ft_dec_hex_l(dec / 16);
		dec = dec % 16;
	}
	if (dec < 10)
		ft_putchar_fd((dec + 48), 1);
	else
		ft_putchar_fd((dec + (97 - 10)), 1);
}
