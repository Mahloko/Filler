/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trimming.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:57:35 by mmahloko          #+#    #+#             */
/*   Updated: 2018/07/29 17:52:12 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int			trim_rw(t_player *obj)
{
	int		rw;
	int		col;
	int		start;

	rw = 0;
	col = 0;
	while (obj->token[rw] && !ft_strchr(obj->token[rw], '*'))
		rw++;
	start = rw;
	rw = obj->tk_dim.y - 1;
	while (rw >= 0 && !ft_strchr(obj->token[rw], '*'))
		rw--;
	rw = rw - start + 1;
	return (rw);
}

static t_point		trim_col(t_player *obj)
{
	int		rw;
	int		col;
	t_point	cl;

	rw = 0;
	cl.x = obj->tk_dim.x;
	cl.y = 0;
	while (rw < obj->tk_dim.y)
	{
		col = 0;
		while (obj->token[rw][col])
		{
			if (obj->token[rw][col] == '*')
			{
				if (cl.x > col)
					cl.x = col;
				if (cl.y < col)
					cl.y = col;
			}
			col++;
		}
		rw++;
	}
	cl.y = cl.y - cl.x + 1;
	return (cl);
}

void				trim(t_player *obj)
{
	int		rw_o;
	int		rw_nw;
	t_point	cl;
	int		i;

	rw_nw = trim_rw(obj);
	cl = trim_col(obj);
	obj->tk = (char **)malloc(sizeof(char *) * (rw_nw + 1));
	rw_o = 0;
	i = 0;
	while (obj->token[rw_o] && !ft_strchr(obj->token[rw_o], '*'))
		rw_o++;
	while (i < rw_nw)
		obj->tk[i++] = ft_strsub(obj->token[rw_o++], cl.x, cl.y);
	obj->tk[i] = NULL;
	obj->p_dim.x = cl.y;
	obj->p_dim.y = i;
}
