/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validpath_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:22:21 by yyasar            #+#    #+#             */
/*   Updated: 2023/06/07 14:30:27 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_check(t_data *err, int x, int y)
{
	if (err->map[y][x + 1] == 'E')
		err->ch_exit = 1;
	else if (err->map[y][x - 1] == 'E')
		err->ch_exit = 1;
	else if (err->map[y - 1][x] == 'E')
		err->ch_exit = 1;
	else if (err->map[y + 1][x] == 'E')
		err->ch_exit = 1;
}

void	coin_check(t_data *g, int x, int y)
{
	if (g->map[y][x] == 'C')
	{
		g->map[y][x] = 's';
		g->ch_coin--;
	}
	else
		g->map[y][x] = 'n';
}

void	err_map(t_data *g, int x, int y)
{
	if (g->ch_exit != 1 || g->ch_coin != 0)
	{
		exit_check(g, x, y);
		if (g->map[y - 1][x] == 'C' || g->map[y - 1][x] == '0')
		{
			coin_check(g, x, y - 1);
			err_map(g, x, y - 1);
		}
		if (g->map[y + 1][x] == 'C' || g->map[y + 1][x] == '0')
		{
			coin_check(g, x, y + 1);
			err_map(g, x, y + 1);
		}
		if (g->map[y][x + 1] == 'C' || g->map[y][x + 1] == '0')
		{
			coin_check(g, x + 1, y);
			err_map(g, x + 1, y);
		}
		if (g->map[y][x - 1] == 'C' || g->map[y][x - 1] == '0')
		{
			coin_check(g, x - 1, y);
			err_map(g, x - 1, y);
		}
	}
}

void	map_edit(t_data *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->map_y)
	{
		j = 0;
		while (j < g->map_x)
		{
			if (g->map[i][j] == 's')
				g->map[i][j] = 'C';
			if (g->map[i][j] == 'n')
				g->map[i][j] = '0';
			j++;
		}
		i++;
	}
}
// bu fonk da coinlerin hepsinin toplanıp toplanmadığını 
// tüm coinler topklanmışsa fonk çık, eğer yol yoksa toplanamıyorsa error

void	valid_path(t_data *a)
{
	a->ch_coin = a->coin;
	a->ch_exit = 0;
	err_map(a, a->player_x, a->player_y);
	if (a->ch_exit == 1 && a->ch_coin == 0)
		map_edit(a);
	else
		error("No valid path");
}
