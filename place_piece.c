/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 10:25:51 by mmahloko          #+#    #+#             */
/*   Updated: 2018/08/04 13:14:48 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	play(t_player *obj)
{
	int		rw;
	int		col;
	char	*str;

	rw = -1;
	col = -1;
	if (obj->bad == 1)
		return ;
	while (++rw <= obj->tk_dim.y)
		if ((str = ft_strstr(obj->token[rw], obj->tk[0])))
		{
			obj->p_co.y = obj->p_co.y - rw;
			while (++col <= obj->tk_dim.x)
				if (&(obj->token[rw][col]) == str)
				{
					obj->p_co.x = obj->p_co.x - col;
					return ;
				}
		}
}
