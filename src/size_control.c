/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:10:38 by yyasar            #+#    #+#             */
/*   Updated: 2023/06/04 13:36:23 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	size_control(t_data *data)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	fd = open(data->map_tmp, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	j = ft_strlen(line);
	while (1)
	{
		free(line);
		i++;
		line = get_next_line(fd);
		if (line[0] == '\0')
			break ;
		if (j != ft_strlen(line))
			error("map is not rectangular");
	}
	if (!*line)
		free(line);
	data->map_height = i;
	data->map_width = j - 1;
	close(fd);
}

void	wall_control(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->map_width)
		if (data->map[0][x++] != '1')
			error("first line wall error");
	x = 0;
	while (x < data->map_width)
		if (data->map[data->map_height - 1][x++] != '1')
			error("last line wall error ");
	while (y < data->map_height)
		if (data->map[y++][0] != '1')
			error("left walls error");
	y = 0;
	while (y < data->map_height)
		if (data->map[y++][data->map_width - 1] != '1')
			error("right walls error");
}

void	min_eleman_control(t_data *data)
{
	if (data->player_count != 1)
		error("only one player please");
	if (data->exit_count != 1)
		error("please only one exit");
	if (data->coin_count < 1)
		error("min one coin");
	if (data->wall_count < 9)
		error("wrong map");
	if (data->unwanted_character_count != 0)
		error("unrecognized error on map");
}
