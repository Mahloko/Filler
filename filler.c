/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:49:44 by mmahloko          #+#    #+#             */
/*   Updated: 2018/08/04 13:10:25 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_get_player(t_player *obj)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_strchr(line, '1'))
	{
		obj->c = ft_strdup("Oo\0");
		obj->o = ft_strdup("Xx\0");
	}
	else if (ft_strchr(line, '2'))
	{
		obj->c = ft_strdup("Xx\0");
		obj->o = ft_strdup("Oo\0");
	}
	ft_strdel(&line);
}

void	get_map(t_player *obj)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	get_next_line(0, &line);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	ft_strdel(&line);
	obj->map = (char **)malloc(sizeof(char *) * (obj->map_dim.y + 1));
	while (j < obj->map_dim.y)
	{
		get_next_line(0, &line);
		obj->map[j++] = ft_strdup(&line[i]);
		ft_strdel(&line);
	}
	obj->map[j] = NULL;
}

void	get_token(t_player *obj)
{
	char	*line;
	int		i;

	i = 0;
	obj->token = (char **)malloc(sizeof(char *) * (obj->tk_dim.y + 1));
	while (i < obj->tk_dim.y)
	{
		get_next_line(0, &line);
		obj->token[i++] = ft_strdup(line);
		ft_strdel(&line);
	}
	obj->token[i] = NULL;
}

void	ft_dimentions(t_player *obj)
{
	char	*line;
	size_t	i;

	i = 0;
	if (get_next_line(0, &line) == 1)
	{
		while (line[i] != ' ' && line[i])
			i++;
		if (ft_strstr(line, "Plateau"))
			obj->map_dim.y = ft_atoi(&line[i]);
		else
			obj->tk_dim.y = ft_atoi(&line[i]);
		i++;
		while (line[i] >= '0' && line[i] <= '9' && line[i])
			i++;
		if (ft_strstr(line, "Plateau"))
			obj->map_dim.x = ft_atoi(&line[i]);
		else
			obj->tk_dim.x = ft_atoi(&line[i]);
		ft_strdel(&line);
	}
	else
		obj->bad = 1;
}

int		main(void)
{
	t_player	obj;

	ft_get_player(&obj);
	while (1)
	{
		obj.bad = 0;
		ft_dimentions(&obj);
		if (obj.bad == 1)
			break ;
		get_map(&obj);
		ft_dimentions(&obj);
		get_token(&obj);
		ai(&obj);
		ft_putnbr(obj.p_co.y);
		ft_putchar(' ');
		ft_putnbr(obj.p_co.x);
		ft_putchar('\n');
		obj.p_co.y = 0;
		obj.p_co.x = 0;
	}
	del_players(&obj);
	return (0);
}
