/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 08:53:33 by pvieira-          #+#    #+#             */
/*   Updated: 2022/07/05 10:21:47 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	define_type(char c, va_list lst)
{
	if (c == 'c')
		return (out_c(lst));
	else if (c == 's')
		return (out_s(lst));
	else if (c == 'p')
		return (out_p(lst));
	else if (c == 'i' || c == 'd')
		return (out_id(lst));
	else if (c == 'u')
		return (out_u(lst));
	else if (c == 'x')
		return (out_l_x(lst));
	else if (c == 'X')
		return (out_u_x(lst));
	else
		return (out_perc());
}

static int	no_placeholder(const char *s, int i)
{
	int	ret_count;

	ret_count = 0;
	if (s[i] == '%')
	{
		ft_putchar_fd(' ', 1);
		ret_count++;
	}
	else
	{
		ft_putchar_fd(s[i], 1);
		ret_count++;
	}
	return (ret_count);
}

int	ft_printf(const char *s, ...)
{
	va_list	lst;
	int		i;
	int		ret_count;

	ret_count = 0;
	i = 0;
	va_start(lst, s);
	while (s[i])
	{
		if (s[i] == '%' && ft_strchr("cspdiuxX%", s[i + 1]))
		{
			ret_count += define_type(s[i + 1], lst);
			i++;
		}
		else
			ret_count += no_placeholder(s, i);
		i++;
	}
	va_end(lst);
	return (ret_count);
}
