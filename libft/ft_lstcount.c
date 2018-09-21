/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 10:49:41 by mmahloko          #+#    #+#             */
/*   Updated: 2018/06/13 11:12:17 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstcount(t_list **alst)
{
	t_list	*cursor;
	size_t	i;

	if (!alst)
		return (0);
	i = 0;
	cursor = (*alst);
	while (cursor)
	{
		i++;
		cursor = cursor->next;
	}
	return (i);
}
