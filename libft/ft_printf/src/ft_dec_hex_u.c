/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_hex_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 09:23:41 by pvieira-          #+#    #+#             */
/*   Updated: 2022/06/30 19:17:57 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dec_hex_u(unsigned int dec)
{
	if (dec >= 16)
	{
		ft_dec_hex_u(dec / 16);
		dec = dec % 16;
	}
	if (dec < 10)
		ft_putchar_fd((dec + 48), 1);
	else
		ft_putchar_fd((dec + (65 - 10)), 1);
}
