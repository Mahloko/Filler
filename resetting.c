/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resetting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 12:56:40 by mmahloko          #+#    #+#             */
/*   Updated: 2018/08/04 12:56:45 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_del_list(t_moves **lst)
{
	t_moves		*temp;

	if (!*lst)
		return ;
	while ((*lst))
	{
		temp = *lst;
		*lst = temp->next;
		free(temp);
	}
}

void	delarr(t_player *obj)
{
	int		i;

	i = 0;
	while (i <= obj->map_dim.y)
		ft_strdel(&obj->map[i++]);
	ft_strdel(obj->map);
	i = 0;
	while (i <= obj->tk_dim.y)
		ft_strdel(&obj->token[i++]);
	ft_strdel(obj->token);
	i = 0;
	while (i <= obj->p_dim.y)
		ft_strdel(&obj->tk[i++]);
	ft_strdel(obj->tk);
}

void	del_players(t_player *obj)
{
	ft_strdel(&obj->c);
	ft_strdel(&obj->o);
}
