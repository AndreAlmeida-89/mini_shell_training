/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:05:55 by pvieira-          #+#    #+#             */
/*   Updated: 2023/06/12 11:49:15 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../gnl/get_next_line.h"
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	ft_dec_hex_l(unsigned int dec);
void	ft_dec_hex_u(unsigned int dec);
int		out_c(va_list lst);
int		out_s(va_list lst);
int		out_p(va_list lst);
int		out_id(va_list lst);
int		out_u(va_list lst);
int		out_l_x(va_list lst);
int		out_u_x(va_list lst);
int		out_perc(void);
#endif
