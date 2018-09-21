/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:46:00 by mmahloko          #+#    #+#             */
/*   Updated: 2018/08/05 08:07:20 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_moves
{
	struct s_point		posbl;
	struct s_moves		*next;
}						t_moves;

typedef struct			s_player
{
	char				*c;
	char				*o;
	char				**map;
	char				**token;
	char				**tk;
	int					bad;
	struct s_point		map_dim;
	struct s_point		tk_dim;
	struct s_point		p_dim;
	struct s_point		p_co;
}						t_player;

void					ai(t_player *obj);
void					trim(t_player *obj);
void					play(t_player *obj);
void					delarr(t_player *obj);
void					del_players(t_player *obj);
void					ft_del_list(t_moves	**lst);
void					middle(t_moves *moves, t_player *obj);
void					lowest_rw(t_moves *moves, t_player *obj);
void					higest_col(t_moves *moves, t_player *obj);

#endif
