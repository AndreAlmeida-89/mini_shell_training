/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:42:38 by pvieira-          #+#    #+#             */
/*   Updated: 2022/07/15 11:58:16 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*search_back_slash(int fd, char *bkp)
{
	int		len;
	char	*buf;

	len = 1;
	if (bkp && ft_strchr_gnl(bkp, '\n'))
		return (bkp);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (len > 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[len] = '\0';
		if (*buf != '\0')
			bkp = ft_strjoin_gnl(bkp, buf);
		if (ft_strchr_gnl(buf, '\n'))
			break ;
	}
	free(buf);
	return (bkp);
}

char	*cut_bkp(char *bkp)
{
	size_t	i;
	size_t	j;
	char	*aux;

	i = 0;
	while (bkp[i] != '\n' && bkp[i] != '\0')
		i++;
	if (bkp[i] == '\n')
		i++;
	aux = malloc(sizeof(char) * (ft_strlen_gnl(bkp) - i) + 1);
	j = 0;
	while (bkp[i])
		aux[j++] = bkp[i++];
	aux[j] = '\0';
	free(bkp);
	return (aux);
}

char	*printable_phrase(char *bkp)
{
	size_t	count;
	char	*print;

	count = 0;
	while (bkp[count] != '\n' && bkp[count])
		count++;
	if (bkp[count] == '\n')
		count++;
	print = malloc(sizeof(char) * (count + 1));
	if (!print)
		return (NULL);
	ft_memmove(print, bkp, count);
	print[count] = '\0';
	return (print);
}

char	*get_next_line(int fd)
{
	static char	*bkp;
	char		*print;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bkp = search_back_slash(fd, bkp);
	if (!bkp)
		return (NULL);
	if (*bkp == '\0')
	{
		free(bkp);
		return (NULL);
	}
	print = printable_phrase(bkp);
	bkp = cut_bkp(bkp);
	return (print);
}
