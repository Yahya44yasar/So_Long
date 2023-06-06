/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:19:40 by yyasar            #+#    #+#             */
/*   Updated: 2023/06/04 18:16:01 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	recursive_func(int **int_map, t_data *data, int x, int y)
{	
	if (data->map[y][x] == 'P' || data->map[y][x] == 'C')
		data->i_map.read_count++;
	if (data->map[y][x + 1] != '1' && int_map[y][x + 1] < 1)
	{
		int_map[y][x + 1] = int_map[y][x] + 1;
		data->i_map.r = recursive_func(int_map, data, x + 1, y);
	}
	if (data->map[y + 1][x] != '1' && int_map[y + 1][x] < 1)
	{
		int_map[y + 1][x] = int_map[y][x] + 1;
		data->i_map.b = recur_func(int_map, data, x, y + 1);
	}
	if (data->map[y][x - 1] != '1' && int_map[y][x - 1] < 1)
	{
		int_map[y][x - 1] = int_map[y][x] + 1;
		data->i_map.l = recur_func(int_map, data, x - 1, y);
	}
	if (data->map[y - 1][x] != '1' && int_map[y - 1][x] < 1)
	{
		int_map[y - 1][x] = int_map[y][x] + 1;
		data->i_map.t = recur_func(int_map, data, x, y - 1);
	}
	if ((data->i_map.r || data->i_map.l || data->i_map.b || data->i_map.t))
		return (1);
	return (0);
}

static void	int_map_free(int **int_map, t_data *list)
{
	int	i;

	i = 0;
	while (i < list->map_height)
	{
		free(int_map[i]);
		i++;
	}
	free(int_map);
}

void	placeholder(t_data *data, int x, int y)
{
	int	**int_map;
	int	i;
	int	j;

	i = 0;
	int_map = (int **)malloc(sizeof(int) * data->map_height);
	while (i < data->map_height)
	{
		int_map[i] = (int *)malloc(sizeof(int) * data->map_width);
		j = 0;
		while (j < data->map_width)
		{
			int_map[i][j] = 0;
			j++;
		}
		i++;
	}
	int_map[y][x] = 1;
	data->i_map.read_count = 0;
	data->i_map.step_count = 0;
	recursive_func(int_map, data, x, y);
	int_map_free(int_map, data);
}
