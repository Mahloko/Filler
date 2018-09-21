/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 13:23:16 by mmahloko          #+#    #+#             */
/*   Updated: 2018/08/05 12:28:15 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	low_col(t_moves *moves, t_player *obj)
{
	t_moves	*tmp;

	tmp = moves;
	while (tmp->next)
	{
		if (tmp->posbl.x < moves->posbl.x)
			moves = tmp;
		tmp = tmp->next;
	}
	obj->p_co = moves->posbl;
}

void			lowest_rw(t_moves *moves, t_player *obj)
{
	t_moves	*tmp;

	if (!moves)
		return ;
	tmp = moves;
	if (ft_strchr(obj->map[0], '.') && !ft_strchr(obj->map[0], obj->c[0]))
	{
		while (tmp->next)
			tmp = tmp->next;
		obj->p_co = tmp->posbl;
		return ;
	}
	low_col(moves, obj);
}

void			higest_col(t_moves *moves, t_player *obj)
{
	t_moves *tmp;

	if (!moves)
		return ;
	tmp = moves;
	if (obj->map[0][0] == '.')
	{
		while (moves->next)
			moves = moves->next;
		obj->p_co = moves->posbl;
		return ;
	}
	else if (obj->map[obj->map_dim.y - 1][obj->map_dim.x - 1] == '.')
	{
		obj->p_co = moves->posbl;
		return ;
	}
	while (tmp->next)
	{
		if (tmp->posbl.x > moves->posbl.x)
			moves = tmp;
		tmp = tmp->next;
	}
	obj->p_co = moves->posbl;
}

static	void	ft_pushup(t_moves *moves, t_player *obj)
{
	t_moves *tmp;

	tmp = moves;
	while (tmp->next)
	{
		if (tmp->posbl.x > moves->posbl.x && tmp->posbl.y < moves->posbl.y)
			moves = tmp;
		tmp = tmp->next;
	}
	obj->p_co = tmp->posbl;
}

void			middle(t_moves *moves, t_player *obj)
{
	t_moves	*tmp;

	if (!moves)
		return ;
	tmp = moves;
	if (!ft_strchr(obj->map[obj->map_dim.y - 1], obj->c[0]))
	{
		while (tmp->next)
		{
			if (tmp->posbl.x < moves->posbl.x)
				moves = tmp;
			tmp = tmp->next;
		}
		obj->p_co = moves->posbl;
		return ;
	}
	if (!ft_strchr(obj->map[0], obj->c[0]) \
			&& obj->map[9][obj->map_dim.x - 1] != obj->o[0])
	{
		ft_pushup(moves, obj);
		return ;
	}
	low_col(moves, obj);
}
