/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:31:21 by pvieira-          #+#    #+#             */
/*   Updated: 2022/07/02 16:31:09 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out_s(va_list lst)
{
	char	*s;

	s = va_arg(lst, char *);
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
