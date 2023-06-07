/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:24:58 by yyasar            #+#    #+#             */
/*   Updated: 2023/06/07 15:29:56 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_format(char *mapname, t_data *data)
{
	int	i;

	i = ft_strlen(mapname);
	if (mapname[i - 1] != 'r' || mapname[i - 2] != 'e'
		|| mapname[i - 3] != 'b' || mapname[i - 4] != '.')
		error(".ber error");
}

void	pce10_control(t_data *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->map_y)
	{
		j = 0;
		while (j < g->map_x && g->map[i][j] != '\0')
		{
			if (!(ft_strchr("0CE1P", g->map[i][j])))
				error("unrecognized characters on the map");
			j++;
		}	
		i++;
	}
}

void	wall_control(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->map_x)
		if (data->map[0][x++] != '1')
			error("first line wall error");
	x = 0;
	while (x < data->map_x)
		if (data->map[data->map_y - 1][x++] != '1')
			error("last line wall error ");
	while (y < data->map_y)
		if (data->map[y++][0] != '1')
			error("left walls error");
	y = 0;
	while (y < data->map_y)
		if (data->map[y++][data->map_x - 1] != '1')
			error("right walls error");
}

void	rectangel_control(t_data *data)
{
	int	i;

	i = 0;
	data->map_x = ft_strlen(data->map[i]);
	if (data->map_x < 3)
		error("the map is too small");
	while (i < data->map_y)
	{
		if (data->map_x != ft_strlen(data->map[i]))
			error("Map not rectangular");
		data->map[i][data->map_x] = '\0';
		i++;
	}
}

void	control_map(t_data *data)
{
	data->player = 0;
	data->exit = 0;
	data->coin = 0;
	data->move = 0;
	rectangel_control(data);
	wall_control(data);
	pce10_control(data);
	char_control(data);
	valid_path(data);
}
