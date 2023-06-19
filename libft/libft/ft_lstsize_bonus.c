/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:18:15 by pvieira-          #+#    #+#             */
/*   Updated: 2022/07/09 10:12:07 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	count;
	t_list	*temp;

	count = 1;
	temp = lst;
	if (lst == NULL)
		return (0);
	while (temp->next != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
