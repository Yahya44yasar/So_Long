/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:13:36 by yyasar            #+#    #+#             */
/*   Updated: 2023/06/07 16:44:55 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_data *g)
{
	int	x;
	int	y;

	x = 50;
	y = 50;
	g->img = malloc(sizeof(t_img));
	g->img->back = mlx_xpm_file_to_image(g->mlx, "xpm/bacgraund.xpm", &x, &y);
	g->img->loot = mlx_xpm_file_to_image(g->mlx, "xpm/adem.xpm", &x, &y);
	g->img->wall = mlx_xpm_file_to_image(g->mlx, "xpm/wire.xpm", &x, &y);
	g->img->player = mlx_xpm_file_to_image(g->mlx, "xpm/taxi.xpm", &x, &y);
	g->img->door = mlx_xpm_file_to_image(g->mlx, "xpm/door.xpm", &x, &y);
	g->img->title = mlx_xpm_file_to_image(g->mlx, "xpm/title.xpm", &x, &y);
}

void	draw_img_ul(t_data *g, int x, int y)
{
	if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->window, g->img->wall,
			x * 50, y * 50);
	if (g->map[y][x] == '0')
		mlx_put_image_to_window(g->mlx, g->window, g->img->back,
			x * 50, y * 50);
	if (g->map[y][x] == 'P')
		mlx_put_image_to_window(g->mlx, g->window, g->img->player,
			x * 50, y * 50);
	if (g->map[y][x] == 'C')
		mlx_put_image_to_window(g->mlx, g->window, g->img->loot,
			x * 50, y * 50);
	if (g->map[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->window, g->img->door,
			x * 50, y * 50);
	if (x == g->map_x / 2 && y == 0)
	{
		mlx_put_image_to_window(g->mlx, g->window, g->img->title,
			x * 50, y * 50);
	}		
}	

void	draw_img(t_data *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->map_y)
	{
		x = 0;
		while (x < g->map_x)
		{
			draw_img_ul(g, x, y);
			x++;
		}
		y++;
	}
}

void	create_mlx(t_data *g)
{
	g->mlx = mlx_init();
	g->window = mlx_new_window(g->mlx, g->map_x * 50, g->map_y * 50, "so_long");
	mlx_hook(g->window, 2, 0, key_func, g);
	put_img(g);
	mlx_loop_hook(g->mlx, redraw_map, g);
	mlx_hook(g->window, 17, 0, exit_hook, g);
	mlx_loop(g->mlx);
}

int	main(int arg, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (arg != 2)
		error("please enter 2 arguments");
	check_format(argv[1], data);
	map_init(data, argv[1]);
	control_map(data);
	create_mlx(data);
}
