/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:34:21 by mmahloko          #+#    #+#             */
/*   Updated: 2018/08/05 08:08:51 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_check(t_player *obj, int rw, int col)
{
	int		j;
	int		i;

	j = 0;
	if (obj->map[rw + obj->p_dim.y - 1][col + obj->p_dim.x - 1])
		while (j < obj->p_dim.y)
		{
			i = 0;
			while (i < obj->p_dim.x)
			{
				if (ft_strchr(obj->o, obj->map[rw + j][col + i]) \
						&& obj->tk[j][i] == '*')
					return (0);
				i++;
			}
			j++;
		}
	else
		return (0);
	return (1);
}

static int		ft_verify(t_player *obj, int rw, int col)
{
	int		j;
	int		i;
	int		count;

	j = 0;
	count = 0;
	while (j < obj->p_dim.y)
	{
		i = 0;
		while (i < obj->p_dim.x)
		{
			if ((ft_strchr(obj->c, obj->map[rw + j][col + i]) \
					&& obj->tk[j][i] == '*'))
				count++;
			i++;
		}
		j++;
	}
	if (count == 1)
		return (1);
	return (0);
}

static void		posible_moves(t_moves **moves, int rw, int col)
{
	t_moves *new;

	if (!(new = (t_moves *)malloc(sizeof(t_moves))))
		return ;
	new->posbl.x = col;
	new->posbl.y = rw;
	new->next = (*moves);
	*moves = new;
}

static	void	valid_moves(t_player *obj, t_moves **moves)
{
	int		rw;
	int		col;

	rw = 0;
	while (rw < obj->map_dim.y)
	{
		if (rw > obj->map_dim.y - obj->p_dim.y)
			break ;
		col = 0;
		while (col < obj->map_dim.x)
		{
			if (col > obj->map_dim.x - obj->p_dim.x)
				break ;
			if (ft_check(obj, rw, col))
				if (ft_verify(obj, rw, col))
					posible_moves(moves, rw, col);
			col++;
		}
		rw++;
	}
}

void			ai(t_player *obj)
{
	t_moves		*moves;

	trim(obj);
	valid_moves(obj, &moves);
	if (moves == NULL)
		obj->bad = 1;
	if (obj->c[0] == 'X' && obj->map_dim.y < 20)
		lowest_rw(moves, obj);
	else if (obj->c[0] == 'X' && obj->map_dim.y < 40)
		middle(moves, obj);
	else
		higest_col(moves, obj);
	play(obj);
	delarr(obj);
	ft_del_list(&moves);
}
