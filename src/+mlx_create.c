/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   +mlx_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:17:53 by yyasar            #+#    #+#             */
/*   Updated: 2023/06/04 17:13:09 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_put(int i, int j, t_data *data)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img.wire,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img.bg,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img.adem,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img.door,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img.taxi,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (data->map[i][j] == 'S')
		mlx_put_image_to_window(data->mlx, data->win, data->img.salih,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (data->map[i][j] == 'Y')
		mlx_put_image_to_window(data->mlx, data->win, data->img.yahya,
			j * IMG_SIZE, i * IMG_SIZE);
}

static	void	map_element_counter(int i, int j, t_data *data)
{
	int	i;

	i = 0;
	if (data->map[i][j] == '1')
		data->wall_count++;
	else if (data->map[i][j] == '0')
		i++;
	else if (data->map[i][j] == 'C' ||
			data->map[i][j] == 'Y' || data->map[i][j] == 'S')
		data->coin_count++;
	else if (data->map[i][j] == 'E')
	{
		data->exit_count++;
		data->exit_x = j;
		data->exit_y = i;
	}
	else if (data->map[i][j] == 'P')
	{
		data->player_count++;
		data->player_x = j;
		data->player_y = i;
	}
}

void	map_create(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			map_element_counter(i, j, data);
			map_put(i, j, data);
			j++;
		}
		i++;
	}
}

void	map_bacgraund_put(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img.bg,
				j * IMG_SIZE, i * IMG_SIZE);
			j++;
		}
		i++;
	}
}
