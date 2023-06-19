/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:15:41 by pvieira-          #+#    #+#             */
/*   Updated: 2022/06/14 09:30:17 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_l;
	size_t	dst_l;
	size_t	f_size;
	size_t	i;
	char	*p;

	i = 0;
	f_size = 0;
	src_l = ft_strlen(src);
	dst_l = ft_strlen(dst);
	p = (char *)src;
	if (dstsize == 0)
		return (src_l);
	if (dstsize <= dst_l)
		return (dstsize + src_l);
	else
		f_size = (src_l + dst_l);
	while (p[i] && (dst_l + 1) < dstsize)
	{
		dst[dst_l] = p[i];
		dst_l++;
		i++;
	}
	dst[dst_l] = '\0';
	return (f_size);
}
