/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:03:57 by yyasar            #+#    #+#             */
/*   Updated: 2023/06/07 16:06:47 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_data *g)
{
	if (g->map[g->player_y - 1][g->player_x] != '1')
	{
		if (g->map[g->player_y - 1][g->player_x] == '0')
		{
			g->map[g->player_y - 1][g->player_x] = 'P';
			g->map[g->player_y][g->player_x] = '0';
		}
		if (g->map[g->player_y - 1][g->player_x] == 'C')
		{
			g->map[g->player_y - 1][g->player_x] = 'P';
			g->map[g->player_y][g->player_x] = '0';
			g->coin--;
		}
		if (g->map[g->player_y - 1][g->player_x] == 'E' && g->coin == 0)
		{
			mlx_clear_window(g->mlx, g->window);
			exit(0);
		}
		if (g->map[g->player_y - 1][g->player_x] != 'E')
		{
			g->player_y--;
			g->move++;
		}
	}
}

void	down(t_data *g)
{
	if (g->map[g->player_y + 1][g->player_x] != '1')
	{
		if (g->map[g->player_y + 1][g->player_x] == '0')
		{
			g->map[g->player_y + 1][g->player_x] = 'P';
			g->map[g->player_y][g->player_x] = '0';
		}
		if (g->map[g->player_y + 1][g->player_x] == 'C')
		{
			g->map[g->player_y + 1][g->player_x] = 'P';
			g->map[g->player_y][g->player_x] = '0';
			g->coin--;
		}
		if (g->map[g->player_y + 1][g->player_x] == 'E' && g->coin == 0)
		{
			mlx_clear_window(g->mlx, g->window);
			exit(0);
		}
		if (g->map[g->player_y + 1][g->player_x] != 'E')
		{
			g->player_y++;
			g->move++;
		}
	}
}

void	left(t_data *g)
{
	if (g->map[g->player_y][g->player_x - 1] != '1')
	{
		if (g->map[g->player_y][g->player_x - 1] == '0')
		{
			g->map[g->player_y][g->player_x - 1] = 'P';
			g->map[g->player_y][g->player_x] = '0';
		}
		if (g->map[g->player_y][g->player_x - 1] == 'C')
		{
			g->map[g->player_y][g->player_x - 1] = 'P';
			g->map[g->player_y][g->player_x] = '0';
			g->coin--;
		}
		if (g->map[g->player_y][g->player_x - 1] == 'E' && g->coin == 0)
		{
			mlx_clear_window(g->mlx, g->window);
			exit(0);
		}
		if (g->map[g->player_y][g->player_x - 1] != 'E')
		{
			g->player_x--;
			g->move++;
		}
	}
}

void	right(t_data *g)
{
	if (g->map[g->player_y][g->player_x + 1] != '1')
	{
		if (g->map[g->player_y][g->player_x + 1] == '0')
		{
			g->map[g->player_y][g->player_x + 1] = 'P';
			g->map[g->player_y][g->player_x] = '0';
		}
		if (g->map[g->player_y][g->player_x + 1] == 'C')
		{
			g->map[g->player_y][g->player_x + 1] = 'P';
			g->map[g->player_y][g->player_x] = '0';
			g->coin--;
		}
		if (g->map[g->player_y][g->player_x + 1] == 'E' && g->coin == 0)
		{
			mlx_clear_window(g->mlx, g->window);
			exit(0);
		}
		if (g->map[g->player_y][g->player_x + 1] != 'E')
		{
			g->player_x++;
			g->move++;
		}
	}
}

int	redraw_map(t_data *g)
{	
	mlx_clear_window(g->mlx, g->window);
	draw_img(g);
	return (0);
}
