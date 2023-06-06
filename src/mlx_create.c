/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:42:25 by yyasar            #+#    #+#             */
/*   Updated: 2023/06/04 17:23:37 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_create(t_data *data)
{
	data->img.bg = mlx_xpm_file_to_image(data->mlx, "img/bacgraund.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.adem = mlx_xpm_file_to_image(data->mlx, "img/adem.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.salih = mlx_xpm_file_to_image(data->mlx, "img/salih.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.yahya = mlx_xpm_file_to_image(data->mlx, "img/yahya.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.wire = mlx_xpm_file_to_image(data->mlx, "img/wire.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.door = mlx_xpm_file_to_image(data->mlx, "img/door.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.door_open = mlx_xpm_file_to_image(data->mlx, "img/door_open.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.taxi = mlx_xpm_file_to_image(data->mlx, "img/taxi.xpm",
			&data->img.img_w, &data->img.img_h);
}

void	map_read(t_data *data)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	fd = open(data->map_tmp, O_RDONLY);
	data->map = (char **)malloc(sizeof(char *) * data->map_height);
	i = 0;
	while (i < data->map_height)
	{
		data->map[i] = (char *)malloc(sizeof(char) * data->map_height);
		if (!data->map)
			error("malloc error on map_read");
		line = get_next_line(fd);
		j = 0;
		while (j < data->map_width)
		{
			data->map[i][j] = line[j];
			j++;
		}
		data->map[i][j] = '\0';
		i++;
		free(line);
	}
	close(fd);
}

static	void	data_init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map_width * IMG_SIZE,
			data->map_height * IMG_SIZE, "SoLong");
	data->coin_count = 0;
	data->exit_count = 0;
	data->player_count = 0;
	data->wall_count = 0;
	data->unwanted_character_count = 0;
	data->step_count = 0;
	data->coin_collected = 0;
}

void	mlx_create(t_data *data)
{
	data_init(data);
	image_create(data);
	map_read(data);
	map_bacgraund_put(data);
	map_create(data);
	wall_control(data);
	min_element_control(data);
	placeholder(data, data->exit_x, data->exit_y);


}
